#!/usr/bin/python3
import dearpygui.dearpygui as dpg
import yaml
import threading
import time
import sys
import os
from Futaba_USB import *


dithering_tuple = ("None", "Floyd-Steinberg", "Atkinson", "Burkes", "Sierra", "Two-Row Sierra", "Sierra-lite", "8x8 Bayer")
brightness_tuple = (100, 150, 250, 325, 450)
connect_flag = False
dev = 0


def write_Settings():
    with open('conf.yaml', 'w') as outfile:
        outfile.write(yaml.dump(tr.config_dict))


def connect_button_callback():
    global connect_flag
    global dev
    if connect_flag is False:
        dpg.configure_item("port_message", default_value="Connecting...", color=[255, 255, 255])
        try:
            dev = usb.core.find(idVendor=0x0483, idProduct=0xcafe)
            if dev is None:
                raise ValueError("Device not found")
        except ValueError:
            dpg.configure_item("port_message", default_value="Device not found", color=[255, 0, 0])
            return

        dev.set_configuration()
        try:
            idproduct = str(usb.util.get_string(dev, dev.iProduct))
            disp_signature = idproduct.split()
        except Exception:
            dpg.configure_item("port_message", default_value="Can't read display signature", color=[255, 0, 0])
            return

        if disp_signature[4] == "4" or "8":
            tr.colors = int(disp_signature[4])
            if disp_signature[6] == "Dual":
                tr.dispmode = disp_signature[6]
            elif disp_signature[6] == "Single":
                tr.dispmode = disp_signature[6]
            else:
                dpg.configure_item("port_message", default_value="Unknown display signature (mode)", color=[255, 0, 0])
                print(disp_signature)
                print("Unknown display signature (mode)")
                return
        else:
            dpg.configure_item("port_message", default_value="Unknown display signature (colors)", color=[255, 0, 0])
            print(disp_signature)
            print("Unknown display signature (colors)")
            return

        dpg.configure_item("port_message", default_value="Connected", color=[0, 255, 0])
        dpg.configure_item("signature_message", default_value=str(tr.colors) + " Colors / " + tr.dispmode + " Mode")
        dpg.configure_item("connect_button", show=False)
        dpg.configure_item("display_brightness_slider", enabled=True, show=True)
        dpg.configure_item("display_brightness_message", color=[255, 255, 255])
        dpg.configure_item("start_button", enabled=True, show=True)

        connect_flag = True
        t1 = threading.Thread(target=tr.main_loop, daemon=True)
        t1.start()


def startbutton_callback():
    global connect_flag
    global dev
    if tr.startflag is False:
        if connect_flag is True:
            tr.dev = dev

            # Clear screen
            dev.ctrl_transfer(bmRequestType=0x41, bRequest=0x50, wValue=0x00, wIndex=0)
            tr.startflag = True
            dpg.configure_item("start_button", label="Stop")
    else:
        tr.startflag = False
        dpg.configure_item("start_button", label="Run")


def display_brightness_callback(sender, app_data):
    global dev
    dev.ctrl_transfer(bmRequestType=0x41, bRequest=0x44, wValue=brightness_tuple[app_data - 1], wIndex=0)


def dithering_combo_callback(sender, app_data):
    tr.config_dict["dithering_method"] = app_data
    write_Settings()


def x_pos_callback(sender, app_data):
    tr.config_dict["capture_x"] = app_data
    write_Settings()


def y_pos_callback(sender, app_data):
    tr.config_dict["capture_y"] = app_data
    write_Settings()


def image_size_callback(sender, app_data):
    tr.config_dict["capture_size"] = app_data
    write_Settings()


def bcg_tab_callcack(sender, app_data):
    if app_data == "manual_tab":
        tr.config_dict["manual_flag"] = True
    elif app_data == "auto_tab":
        tr.config_dict["manual_flag"] = False
    write_Settings()


def tab_start():
    if tr.config_dict["manual_flag"] is True:
        dpg.set_value("manual_auto_tab", "manual_tab")
    elif tr.config_dict["manual_flag"] is False:
        dpg.set_value("manual_auto_tab", "auto_tab")
        if tr.config_dict["clahe_flag"] is True:
            dpg.set_value("he_radio", value="Contrast Limited AHE (CLAHE):")


def brightness_callback(sender, app_data):
    tr.config_dict["brightness"] = app_data
    write_Settings()


def contrast_callback(sender, app_data):
    tr.config_dict["contrast"] = app_data
    write_Settings()


def gamma_callback(sender, app_data):
    tr.config_dict["gamma"] = app_data
    write_Settings()


def he_radio_callback(sender, app_data):
    if app_data == "Histogram equalization":
        tr.config_dict["hist_eq_flag"] = True
        tr.config_dict["clahe_flag"] = False
    else:
        tr.config_dict["hist_eq_flag"] = False
        tr.config_dict["clahe_flag"] = True
    write_Settings()


def clip_limit_callback(sender, app_data):
    tr.config_dict["clip_limit"] = app_data
    write_Settings()


def bcg_zero_callback(sender):
    if sender == "reset_brightness_button":
        dpg.set_value("brightness_slider", 0)
        brightness_callback(0, 0)
    elif sender == "reset_contrast_button":
        dpg.set_value("contrast_slider", 0)
        contrast_callback(0, 0)
    elif sender == "reset_gamma_button":
        dpg.set_value("gamma_slider", 1.0)
        gamma_callback(0, 1.0)
    write_Settings()


def exit_callback():
    tr.startflag = False
    write_Settings()
    time.sleep(0.15)  # Wait until last frame is sent
    dpg.destroy_context()
    os._exit(1)


if __name__ == "__main__":
    window_height = 600
    window_width = 340

    # Read settings from conf.yaml
    try:
        with open('conf.yaml') as config_file:
            config_dict = yaml.safe_load(config_file)
    except Exception:
        config_dict = {"capture_x": 100, "capture_y": 100, "capture_size": 64,
                       "brightness": 0, "contrast": 0, "gamma": 1.0, "clip_limit": 3.0,
                       "dithering_method": "Atkinson", "manual_flag": True, "clahe_flag": False, "hist_eq_flag": True}

    tr = USB_send_data_thread(0, config_dict)

    dpg.create_context()
    dpg.create_viewport(title="Futaba Demo", width=window_width, height=window_height, resizable=False, always_on_top=True)
    dpg.set_viewport_max_height(window_height)
    dpg.set_viewport_max_width(340)
    with dpg.font_registry():
        default_font = dpg.add_font("FreeSans.otf", 22)

    with dpg.window(id="main_window", label="Futaba GP1160A USB Graphical Display", width=window_width, height=window_height, no_move=True, no_resize=True, no_close=True, no_collapse=True):
        dpg.bind_font(default_font)
        with dpg.group(horizontal=True):
            dpg.add_button(tag="connect_button", width=120, label="Connect", callback=connect_button_callback)
            dpg.add_text(tag="port_message", default_value="Disconnected", color=[100, 100, 100])
        dpg.add_text(tag="signature_message", default_value="", color=[200, 200, 200])
        with dpg.group(horizontal=True):
            dpg.add_text(tag="display_brightness_message", default_value="Display brightness:", color=[100, 100, 100])
            dpg.add_slider_int(tag="display_brightness_slider", max_value=5, min_value=1, width=160, callback=display_brightness_callback, default_value=3, enabled=False, show=False)
        dpg.add_separator()

        dpg.add_text("Capture settings:")
        with dpg.group(horizontal=True):
            dpg.add_text("Top:")
            dpg.add_input_int(indent=50, max_value=2000, min_value=1, min_clamped=True, max_clamped=True, step=1, step_fast=100, default_value=config_dict["capture_y"], width=120, callback=y_pos_callback)
        with dpg.group(horizontal=True):
            dpg.add_text("Left:")
            dpg.add_input_int(indent=50, max_value=2000, min_value=1, min_clamped=True, max_clamped=True, step=1, step_fast=100, default_value=config_dict["capture_x"], width=120, callback=x_pos_callback)
        with dpg.group(horizontal=True):
            dpg.add_text("Size:")
            dpg.add_input_int(indent=50, max_value=2000, min_value=1, min_clamped=True, max_clamped=True, default_value=config_dict["capture_size"], width=120, callback=image_size_callback)

        dpg.add_text("Dithering algorithm:")
        dpg.add_combo(items=dithering_tuple, width=200, default_value=config_dict["dithering_method"], callback=dithering_combo_callback)

        with dpg.tab_bar(tag="manual_auto_tab", callback=bcg_tab_callcack):
            with dpg.tab(tag="manual_tab", label="Manual"):
                with dpg.group(horizontal=True, horizontal_spacing=10):
                    dpg.add_text("Brightness:")
                    dpg.add_slider_int(tag="brightness_slider", indent=90, max_value=127, min_value=-127, width=180, callback=brightness_callback, default_value=config_dict["brightness"])
                    dpg.add_button(tag="reset_brightness_button", label=" R ", width=28, callback=bcg_zero_callback)
                with dpg.group(horizontal=True, horizontal_spacing=10):
                    dpg.add_text("Contrast:")
                    dpg.add_slider_int(tag="contrast_slider", indent=90, max_value=127, min_value=-127, width=180, callback=contrast_callback, default_value=config_dict["contrast"])
                    dpg.add_button(tag="reset_contrast_button", label=" R ", width=28, callback=bcg_zero_callback)
                with dpg.group(horizontal=True, horizontal_spacing=10):
                    dpg.add_text("Gamma:")
                    dpg.add_slider_float(tag="gamma_slider", indent=90, min_value=0.1, max_value=7.0, width=180, format="%.1f", callback=gamma_callback, default_value=config_dict["gamma"])
                    dpg.add_button(tag="reset_gamma_button", label=" R ", width=28, callback=bcg_zero_callback)
            with dpg.tab(tag="auto_tab", label="Auto"):
                dpg.add_radio_button(("Histogram equalization", "Contrast Limited AHE (CLAHE):"), tag="he_radio", callback=he_radio_callback)
                with dpg.group(horizontal=True, horizontal_spacing=10):
                    dpg.add_text("Clip limit: ")
                    dpg.add_slider_float(min_value=0.01, max_value=4.0, indent=90, width=200, format="%.2f", callback=clip_limit_callback, default_value=config_dict["clip_limit"])
        dpg.add_separator()
        dpg.add_spacer(height=25)
        dpg.add_button(tag="start_button", label="Run", width=200, indent=55, callback=startbutton_callback, enabled=False, show=False)
    tab_start()
    dpg.setup_dearpygui()
    dpg.set_exit_callback(exit_callback)
    dpg.show_viewport()
    dpg.start_dearpygui()
    dpg.destroy_context()
