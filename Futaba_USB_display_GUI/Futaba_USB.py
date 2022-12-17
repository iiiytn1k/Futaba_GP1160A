import cv2
import numpy as np
import time
from mss import mss
from image_utils import *
import usb.core


DATA_EP = 1


class USB_send_data_thread():
    def __init__(self, dev, config_dict):
        self.dev = 0
        self.config_dict = config_dict
        self.startflag = False
        self.colors = 8
        self.dispmode = "Single"

    def main_loop(self):
        sct = mss()

        if self.dispmode == "Single":
            if self.colors == 4:
                raw_frame = np.zeros((256 * 2, 64), dtype=np.uint8)
            if self.colors == 8:
                raw_frame = np.zeros((256 * 3, 64), dtype=np.uint8)
            output_img = np.zeros((256, 64), dtype=np.uint8)

        if self.colors == 4 and self.dispmode == "Dual":
            raw_frame = np.zeros((256 * 2, 128), dtype=np.uint8)
            output_img = np.zeros((256, 128), dtype=np.uint8)

        if self.colors == 8 and self.dispmode == "Dual":
            raw_frame = np.zeros((256 * 3, 128), dtype=np.uint8)
            output_img = np.zeros((256, 128), dtype=np.uint8)

        output_byte_array = np.zeros(int(raw_frame.shape[0] * raw_frame.shape[1] // 8), dtype=np.uint8)
        t = time.time()

        while True:
            while not self.startflag:
                pass
            while self.startflag:
                if self.dispmode == "Single":
                    capture_settings = {"top": self.config_dict["capture_y"], "left": self.config_dict["capture_x"], "width": self.config_dict["capture_size"] * 4, "height": self.config_dict["capture_size"]}
                if self.dispmode == "Dual":
                    capture_settings = {"top": self.config_dict["capture_y"], "left": self.config_dict["capture_x"], "width": self.config_dict["capture_size"] * 2, "height": self.config_dict["capture_size"]}

                # Capture an image, resizing and converting it to grayscale:
                input_img = np.array(sct.grab(capture_settings))
                input_img = np.rot90(input_img, k=-1)
                input_img = cv2.resize(input_img, (output_img.shape[1], output_img.shape[0]), interpolation=cv2.INTER_AREA)
                input_img = cv2.cvtColor(input_img, cv2.COLOR_BGR2GRAY)

                # Apply brightness, contrast and gamma correction. Manually or automatically.
                if self.config_dict["manual_flag"] is True:
                    input_img = brightness_contrast_correction(input_img, self.config_dict["brightness"], self.config_dict["contrast"])
                    if self.config_dict["gamma"] != 1.0:
                        input_img = gamma_correction(input_img, self.config_dict["gamma"])
                else:
                    if self.config_dict["hist_eq_flag"] is True:
                        input_img = cv2.equalizeHist(input_img)
                    else:
                        clahe = cv2.createCLAHE(clipLimit=self.config_dict["clip_limit"], tileGridSize=(1, 1))
                        input_img = clahe.apply(input_img)

                # Convert to 3 or 8-colors palette w/wo dithering:
                input_img = dithering_gray(input_img, self.config_dict["dithering_method"], self.colors - 1)

                # Swap edge columns
                output_img[:255, :] = input_img[1:256, :]
                output_img[255:, :] = input_img[:1, :]

                # Convert to 2 or 3 monochrome images and stack into one vertical frame:
                img_to_raw_frame(output_img, raw_frame, self.colors - 1)

                # Convert frame to byte array:
                if self.dispmode == "Single":
                    bit_frames_to_byte_array(raw_frame, output_byte_array)
                if self.colors == 4 and self.dispmode == "Dual":
                    bit_frames_to_byte_array(raw_frame[:, :64], output_byte_array[:4096])
                    bit_frames_to_byte_array(raw_frame[:, 64:], output_byte_array[4096:])

                if self.colors == 8 and self.dispmode == "Dual":
                    bit_frames_to_byte_array(raw_frame[:, :64], output_byte_array[:6144])
                    bit_frames_to_byte_array(raw_frame[:, 64:], output_byte_array[6144:])
                # Send byte array via USB:
                self.dev.write(DATA_EP, bytearray(output_byte_array), 2000)

                # Check framerate
                delta = time.time() - t
                if delta < 0.010:
                    time.sleep(0.010 - delta)
                t = time.time()
