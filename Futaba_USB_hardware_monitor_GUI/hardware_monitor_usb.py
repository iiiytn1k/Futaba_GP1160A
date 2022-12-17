import cv2
import numpy as np
import mmap
import usb.core
from struct import unpack
import time
from simple_char_generator import *
from MAHM_tools import *
from image_utils import *


DATA_EP = 1


def draw_hbargraph(image, value, maxvalue, start_point, end_point):
    (x1, y1) = start_point
    (x2, y2) = end_point
    xmax = int((value * (x2 - x1)) / maxvalue + x1)
    cv2.rectangle(image, start_point, (xmax, y2), (170), -1)
    cv2.rectangle(image, start_point, end_point, (89), 1)
    return image


def draw_vbargraph(image, value, maxvalue, start_point, end_point):
    (x1, y1) = start_point
    (x2, y2) = end_point
    ymax = int((value * (y1 - y2)) / maxvalue + y2)
    cv2.rectangle(image, (x1, ymax), (x2, y2), (170), -1)
    cv2.rectangle(image, start_point, end_point, (255), 1)
    return image


class vplot:
    def __init__(self, size):
        self.prev_value = 0
        self.size = size
        (self.y1, self.x1) = size
        self.outimage = np.zeros(self.size, dtype=np.uint8)
        self.front_color = (255)
        self.edge_color = (0)
        self.background_color = (62)
        cv2.rectangle(self.outimage, (0, 0), (self.x1, self.y1), self.background_color, -1)

    def set_colors(self, front_color, edge_color, background_color):
        self.front_color = front_color
        self.edge_color = edge_color
        self.background_color = background_color

    def update_vplot(self, value, maxvalue, redraw=False):
        if redraw:
            self.outimage = np.zeros(self.size, dtype=np.uint8)
            cv2.rectangle(self.outimage, (0, 0), (self.x1, self.y1), self.background_color, -1)
            self.prev_value = 0
        try:
            ymax = int(self.y1 / (maxvalue / value))
        except ZeroDivisionError:
            ymax = 0
        self.outimage[:, :self.x1 - 1] = self.outimage[:, 1:self.x1]
        cv2.line(self.outimage, (self.x1 - 1, self.y1 - 1), (self.x1 - 1, 0), self.background_color, 1)
        cv2.line(self.outimage, (self.x1 - 1, self.y1 - 1), (self.x1 - 1, self.y1 - ymax), self.front_color, 1)
        cv2.line(self.outimage, (self.x1 - 1, self.y1 - ymax), (self.x1 - 2, self.y1 - self.prev_value), self.edge_color, 1)
        self.prev_value = ymax
        return self.outimage

    def draw_vplot(self):
        return self.outimage


# Update entries values
def entries_update(header, entry_dict):
    with mmap.mmap(0, header.headerSize + header.entrySize * header.entryCount, tagname="MAHMSharedMemory", access=mmap.ACCESS_READ) as data:
        entries = data.read(header.headerSize + header.entrySize * header.entryCount)
        for i, entry in enumerate(entry_dict.values()):
            entry.update_values(*unpack(ENTRY_FORMAT, entries[32 + header.entrySize * i:32 + header.entrySize * (i + 1)]))


def hardware_monitor_init(entry_dict):
    # Read header
    with mmap.mmap(0, 32, tagname="MAHMSharedMemory", access=mmap.ACCESS_READ) as data:
        header = MAHM_shared_memory_header(*unpack(HEADER_FORMAT, data.read(32)))
    # Create entries dict
    with mmap.mmap(0, header.headerSize + header.entrySize * header.entryCount, tagname="MAHMSharedMemory", access=mmap.ACCESS_READ) as data:
        entries = data.read(header.headerSize + header.entrySize * header.entryCount)
        for i in range(0, header.entryCount):
            entry = MAHM_shared_memory_entry(*unpack(ENTRY_FORMAT, entries[header.headerSize + header.entrySize * i:header.headerSize + header.entrySize * (i + 1)]))
            entry_dict[entry.name] = entry
    return header


def hardware_monitor_draw(self):
    input_img = np.zeros((64, 256), dtype=np.uint8)
    current_time = time.strftime("%H:%M", time.localtime())
    current_date = time.strftime("%d - %b - %y", time.localtime())

    # Draw frame
    cv2.line(input_img, (128, 0), (128, 63), (85), 1)
    cv2.rectangle(input_img, (0, 0), (127, 8), (255), -1)

    # Draw clock
    input_img = draw_5x7_String(input_img, current_time + "  " + current_date, (1, 1), character_color=0, background_color=255)

    gauges_interval = 16

    # Draw Gauge 1
    if self.gauge_dict["gauge1"] != "None":
        try:
            gauge1_data = self.available_entries_dict[self.gauge_dict["gauge1"]].data
            gauge1_maxlimit = self.available_entries_dict[self.gauge_dict["gauge1"]].maxLimit
            gauge1_units = self.available_entries_dict[self.gauge_dict["gauge1"]].units
        except KeyError:
            gauge1_data = 0
            gauge1_maxlimit = 1
            gauge1_units = " "
        input_img = draw_5x7_String(input_img, self.gauge_dict["gauge1_name"], (130, 0))
        input_img = draw_hbargraph(input_img, gauge1_data, gauge1_maxlimit, (130, 10), (212, 14))
        gauge1_value = "{:>7}".format("{:.0f}".format(gauge1_data) + str(gauge1_units))
        input_img = draw_5x7_String(input_img, gauge1_value, (214, 8))

    # Draw Gauge 2
    if self.gauge_dict["gauge2"] != "None":
        try:
            gauge2_data = self.available_entries_dict[self.gauge_dict["gauge2"]].data
            gauge2_maxlimit = self.available_entries_dict[self.gauge_dict["gauge2"]].maxLimit
            gauge2_units = self.available_entries_dict[self.gauge_dict["gauge2"]].units
        except KeyError:
            gauge2_data = 0
            gauge2_maxlimit = 1
            gauge2_units = " "
        input_img = draw_5x7_String(input_img, self.gauge_dict["gauge2_name"], (130, 0 + gauges_interval))
        input_img = draw_hbargraph(input_img, gauge2_data, gauge2_maxlimit, (130, 10 + gauges_interval), (212, 14 + gauges_interval))
        gauge2_value = "{:>7}".format("{:.0f}".format(gauge2_data) + str(gauge2_units))
        input_img = draw_5x7_String(input_img, gauge2_value, (214, 8 + gauges_interval))

    # Draw Gauge 3
    if self.gauge_dict["gauge3"] != "None":
        try:
            gauge3_data = self.available_entries_dict[self.gauge_dict["gauge3"]].data
            gauge3_maxlimit = self.available_entries_dict[self.gauge_dict["gauge3"]].maxLimit
            gauge3_units = self.available_entries_dict[self.gauge_dict["gauge3"]].units
        except KeyError:
            gauge3_data = 0
            gauge3_maxlimit = 1
            gauge3_units = " "
        input_img = draw_5x7_String(input_img, self.gauge_dict["gauge3_name"], (130, 0 + gauges_interval * 2))
        input_img = draw_hbargraph(input_img, gauge3_data, gauge3_maxlimit, (130, 10 + gauges_interval * 2), (212, 14 + gauges_interval * 2))
        gauge3_value = "{:>7}".format("{:.0f}".format(gauge3_data) + str(gauge3_units))
        input_img = draw_5x7_String(input_img, gauge3_value, (214, 8 + gauges_interval * 2))

    # Draw Gauge 4
    if self.gauge_dict["gauge4"] != "None":
        try:
            gauge4_data = self.available_entries_dict[self.gauge_dict["gauge4"]].data
            gauge4_maxlimit = self.available_entries_dict[self.gauge_dict["gauge4"]].maxLimit
            gauge4_units = self.available_entries_dict[self.gauge_dict["gauge4"]].units
        except KeyError:
            gauge4_data = 0
            gauge4_maxlimit = 1
            gauge4_units = " "
        input_img = draw_5x7_String(input_img, self.gauge_dict["gauge4_name"], (130, 0 + gauges_interval * 3))
        input_img = draw_hbargraph(input_img, gauge4_data, gauge4_maxlimit, (130, 10 + gauges_interval * 3), (212, 14 + gauges_interval * 3))
        gauge4_value = "{:>7}".format("{:.0f}".format(gauge4_data) + str(gauge4_units))
        input_img = draw_5x7_String(input_img, gauge4_value, (214, 8 + gauges_interval * 3))

    # Draw Plot 1
    if self.gauge_dict["plot1_gauge"] != "None":
        try:
            plot1_data = self.available_entries_dict[self.gauge_dict["plot1_gauge"]].data
            plot1_maxlimit = self.available_entries_dict[self.gauge_dict["plot1_gauge"]].maxLimit
            plot1_units = self.available_entries_dict[self.gauge_dict["plot1_gauge"]].units
        except KeyError:
            plot1_data = 0
            plot1_maxlimit = 0
            plot1_units = " "
        plot1_img = self.plot1.update_vplot(plot1_data, plot1_maxlimit, self.plot1_redraw_flag)
        y_offset = 19
        x_offset = 0
        input_img[y_offset:y_offset + plot1_img.shape[0], x_offset:x_offset + plot1_img.shape[1]] = plot1_img
        plot1_value = self.gauge_dict["plot1_gauge_name"] + ": " + "{:>4}".format("{:.0f}".format(plot1_data) + str(plot1_units))
        cv2.rectangle(input_img, (0, 9), (127, 19), (36), -1)
        input_img = draw_5x7_String(input_img, plot1_value, (1, 10), background_color=(36))
        self.plot1_redraw_flag = False

    # Draw Plot 2
    if self.gauge_dict["plot2_gauge"] != "None":
        try:
            plot2_data = self.available_entries_dict[self.gauge_dict["plot2_gauge"]].data
            plot2_maxlimit = self.available_entries_dict[self.gauge_dict["plot2_gauge"]].maxLimit
            plot2_units = self.available_entries_dict[self.gauge_dict["plot2_gauge"]].units
        except KeyError:
            plot2_data = 0
            plot2_maxlimit = 0
            plot2_units = " "
        plot2_img = self.plot2.update_vplot(plot2_data, plot2_maxlimit, self.plot2_redraw_flag)
        y_offset = 19
        x_offset = 64
        input_img[y_offset:y_offset + plot2_img.shape[0], x_offset:x_offset + plot2_img.shape[1]] = plot2_img
        plot2_value = self.gauge_dict["plot2_gauge_name"] + ": " + "{:>4}".format("{:.0f}".format(plot2_data) + str(plot2_units))
        input_img = draw_5x7_String(input_img, plot2_value, (1, 56))
        self.plot2_redraw_flag = False
    return input_img


class USB_send_data_thread():
    def __init__(self, gauge_dict):
        self.gauge_dict = gauge_dict
        self.dev = 0
        self.startflag = False
        self.colors = 8
        self.dispmode = "Single"

    def main_loop(self):
        if self.dispmode == "Single":
            if self.colors == 4:
                raw_frame = np.zeros((256 * 2, 64), dtype=np.uint8)
            if self.colors == 8:
                raw_frame = np.zeros((256 * 3, 64), dtype=np.uint8)
            output_img = np.zeros((256, 64), dtype=np.uint8)

        if self.colors == 4 and self.dispmode == "Dual":
            raw_frame = np.zeros((256 * 2, 128), dtype=np.uint8)
            output_img = np.zeros((256, 64), dtype=np.uint8)

        if self.colors == 8 and self.dispmode == "Dual":
            raw_frame = np.zeros((256 * 3, 128), dtype=np.uint8)
            output_img = np.zeros((256, 64), dtype=np.uint8)

        output_byte_array = np.zeros(int(raw_frame.shape[0] * raw_frame.shape[1] // 8), dtype=np.uint8)

        self.available_entries_dict = ({})
        header = hardware_monitor_init(self.available_entries_dict)
        hardware_monitor_img = np.zeros((64, 256), dtype=np.uint8)

        self.plot1 = vplot(size=(35, 64))
        self.plot1.set_colors(front_color=(255), edge_color=(0), background_color=(36))
        self.plot1_redraw_flag = True

        self.plot2 = vplot(size=(35, 64))
        self.plot2.set_colors(front_color=(109), edge_color=(255), background_color=(0))
        self.plot2_redraw_flag = True

        while True:
            entries_update(header, self.available_entries_dict)
            hardware_monitor_img = hardware_monitor_draw(self)
            input_img = np.rot90(hardware_monitor_img, k=-1)

            # Convert to 3 or 8 - colors palette wo dithering:
            input_img = dithering_gray(input_img, "None", self.colors - 1)

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
            if self.colors == 8 and self.dispmode == "Dual":
                bit_frames_to_byte_array(raw_frame[:, :64], output_byte_array[:6144])

            # Send byte array via USB:
            self.dev.write(DATA_EP, bytearray(output_byte_array), 2000)
            time.sleep(self.gauge_dict["refresh_time"] / 1000)
