#!/usr/bin/python3
import dearpygui.dearpygui as dpg
import threading
import time
import yaml
from MAHM_tools import *
from struct import unpack
import mmap
import os
from hardware_monitor_usb import *


brightness_tuple = (100, 150, 250, 325, 450)
connect_flag = False
dev = 0


def check_header():
    with mmap.mmap(0, 32, tagname="MAHMSharedMemory", access=mmap.ACCESS_READ) as data:
        header = MAHM_shared_memory_header(*unpack(HEADER_FORMAT, data.read(32)))
    return header.signature


def get_entries_list():
    entries_list = []

    # Read header
    with mmap.mmap(0, 32, tagname="MAHMSharedMemory", access=mmap.ACCESS_READ) as data:
        header = MAHM_shared_memory_header(*unpack(HEADER_FORMAT, data.read(32)))

    # Read all entries names to list
    with mmap.mmap(0, header.headerSize + header.entrySize * header.entryCount, tagname="MAHMSharedMemory", access=mmap.ACCESS_READ) as data:
        entries = data.read(header.headerSize + header.entrySize * header.entryCount)
        for i in range(0, header.entryCount):
            entry = MAHM_shared_memory_entry(*unpack(ENTRY_FORMAT, entries[header.headerSize + header.entrySize * i:header.headerSize + header.entrySize * (i + 1)]))
            entries_list.append(entry.name)
    return entries_list


def gauges_callback(sender, data):
    if sender == "plot1_gauge":
        tr.plot1_redraw_flag = True
    if sender == "plot2_gauge":
        tr.plot2_redraw_flag = True
    tr.gauge_dict[sender] = data

    # Change custom name text field and dict value
    dpg.set_value(sender + "_name", data)
    tr.gauge_dict[sender + "_name"] = data
    write_gauges_to_file()


def gauges_name_callback(sender, data):
    if (len(data) > 21):
        dpg.set_value(sender, data[:21])
        data = data[:21]
    tr.gauge_dict[sender] = data
    write_gauges_to_file()


def gauges_name_auto_button_callback(sender, data):
    dpg.set_value(sender[:11], tr.gauge_dict[sender[:-5]])
    tr.gauge_dict[sender[:11]] = tr.gauge_dict[sender[:-5]]


def refresh_callback(sender, data):
    tr.gauge_dict["refresh_time"] = data
    write_gauges_to_file()


def connect_button_callback():
    global connect_flag
    global dev
    if connect_flag is False:
        dpg.configure_item("port_message", default_value="Connecting...", color=(255, 255, 255))
        try:
            dev = usb.core.find(idVendor=0x0483, idProduct=0xcafe)
            if dev is None:
                raise ValueError("Device not found")
        except ValueError:
            dpg.configure_item("port_message", default_value="Device not found", color=(255, 0, 0))
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

        dpg.configure_item("port_message", default_value="Connected", color=(0, 255, 0))
        dpg.configure_item("signature_message", default_value=str(tr.colors) + " Colors / " + tr.dispmode + " Mode")
        dpg.configure_item("connect_button", show=False)
        dpg.configure_item("display_brightness_slider", enabled=True, show=True)
        dpg.configure_item("display_brightness_message", color=(255, 255, 255))

        # Clear screen
        dev.ctrl_transfer(bmRequestType=0x41, bRequest=0x50, wValue=0x00, wIndex=0)

        connect_flag = True
        tr.dev = dev
        t1 = threading.Thread(target=tr.main_loop, daemon=True)
        t1.start()


def display_brightness_callback(sender, app_data):
    global dev
    dev.ctrl_transfer(bmRequestType=0x41, bRequest=0x44, wValue=brightness_tuple[app_data - 1], wIndex=0)


def exit_callback():
    time.sleep(0.15)  # Wait until last frame is sent
    dpg.destroy_context()
    os._exit(1)


def write_gauges_to_file():
    with open("gauges.yaml", "w") as outfile:
        outfile.write(yaml.dump(tr.gauge_dict))


if __name__ == "__main__":
    if check_header() != "MHAM":
        dpg.create_context()
        dpg.create_viewport(title="Futaba hardware monitor demo", width=398, height=150, min_height=150, resizable=False, always_on_top=False)
        with dpg.window(label="Error", width=380, height=100, menubar=False, no_move=True, no_resize=True, no_close=True, no_collapse=True):
            dpg.add_text("MSI Afterburner not running or something went wrong")
            dpg.add_separator()
            dpg.add_button(label="Exit", callback=exit_callback)
        dpg.setup_dearpygui()
        dpg.show_viewport()
        dpg.start_dearpygui()

    entries_list = ["None"]
    entries_list.extend(get_entries_list())

    # Read gauges dict from gauges.json
    try:
        with open("gauges.yaml") as gauges_file:
            gauges_dict = yaml.safe_load(gauges_file)
    except Exception:
        gauges_dict = {"gauge1": "None", "gauge2": "None", "gauge3": "None", "gauge4": "None", "plot1_gauge": "None", "plot2_gauge": "None",
                       "gauge1_name": "", "gauge2_name": "", "gauge3_name": "", "gauge4_name": "", "plot1_gauge_name": "", "plot2_gauge_name": "", "refresh_time": 500}
    ui_width = 470
    ui_height = 600
    dpg.create_context()
    dpg.create_viewport(title="Futaba hardware monitor demo", width=ui_width, height=ui_height, resizable=False, always_on_top=True)
    dpg.set_viewport_max_height(ui_height)
    dpg.set_viewport_max_width(ui_width)

    with dpg.font_registry():
        with dpg.font("FreeSans.otf", 22, default_font=True, id="FreeSans"):
            dpg.add_font_range_hint(dpg.mvFontRangeHint_Cyrillic)

    with dpg.window(id="main_window", label="Futaba USB Hardware Monitor", width=ui_width, height=ui_height, no_move=True, no_resize=True, no_close=True, no_collapse=True):
        dpg.bind_font("FreeSans")

        with dpg.group(horizontal=True):
            dpg.add_button(tag="connect_button", width=120, label="Connect", callback=connect_button_callback)
            dpg.add_text(tag="port_message", default_value="Disconnected", color=(100, 100, 100))
        dpg.add_text(tag="signature_message", default_value="")

        with dpg.group(horizontal=True):
            dpg.add_text(tag="display_brightness_message", default_value="Display brightness:", color=(100, 100, 100))
            dpg.add_slider_int(tag="display_brightness_slider", max_value=5, min_value=1, width=160, callback=display_brightness_callback, default_value=3, enabled=False, show=False)
        dpg.add_separator()

        with dpg.group():
            with dpg.group(horizontal=True, horizontal_spacing=105):
                dpg.add_text("Select sensor:")
                dpg.add_text("Custom name:")

            with dpg.group(horizontal=True):
                dpg.add_combo(tag="gauge1", default_value=gauges_dict["gauge1"], items=entries_list, width=200, callback=gauges_callback)
                dpg.add_input_text(tag="gauge1_name", default_value=gauges_dict["gauge1_name"], width=200, callback=gauges_name_callback)
                dpg.add_button(tag="gauge1_name_auto", label="A", callback=gauges_name_auto_button_callback)
                with dpg.tooltip(dpg.last_item()):
                    dpg.add_text("Reset sensor name")

            with dpg.group(horizontal=True):
                dpg.add_combo(tag="gauge2", default_value=gauges_dict["gauge2"], items=entries_list, width=200, callback=gauges_callback)
                dpg.add_input_text(tag="gauge2_name", default_value=gauges_dict["gauge2_name"], width=200, callback=gauges_name_callback)
                dpg.add_button(tag="gauge2_name_auto", label="A", callback=gauges_name_auto_button_callback)
                with dpg.tooltip(dpg.last_item()):
                    dpg.add_text("Reset sensor name")

            with dpg.group(horizontal=True):
                dpg.add_combo(tag="gauge3", default_value=gauges_dict["gauge3"], items=entries_list, width=200, callback=gauges_callback)
                dpg.add_input_text(tag="gauge3_name", default_value=gauges_dict["gauge3_name"], width=200, callback=gauges_name_callback)
                dpg.add_button(tag="gauge3_name_auto", label="A", callback=gauges_name_auto_button_callback)
                with dpg.tooltip(dpg.last_item()):
                    dpg.add_text("Reset sensor name")

            with dpg.group(horizontal=True):
                dpg.add_combo(tag="gauge4", default_value=gauges_dict["gauge4"], items=entries_list, width=200, callback=gauges_callback)
                dpg.add_input_text(tag="gauge4_name", default_value=gauges_dict["gauge4_name"], width=200, callback=gauges_name_callback)
                dpg.add_button(tag="gauge4_name_auto", label="A", callback=gauges_name_auto_button_callback)
                with dpg.tooltip(dpg.last_item()):
                    dpg.add_text("Reset sensor name")
            dpg.add_separator()

            with dpg.group(horizontal=True, horizontal_spacing=120):
                dpg.add_text("Plot1 sensor:")
                dpg.add_text("Plot1 name:")
            with dpg.group(horizontal=True):
                dpg.add_combo(tag="plot1_gauge", default_value=gauges_dict["plot1_gauge"], items=entries_list, width=200, callback=gauges_callback)
                dpg.add_input_text(tag="plot1_gauge_name", default_value=gauges_dict["plot1_gauge_name"], width=200, callback=gauges_name_callback)
                dpg.add_button(tag="plot1_gauge_name_auto", label="A", callback=gauges_name_auto_button_callback)
                with dpg.tooltip(dpg.last_item()):
                    dpg.add_text("Reset sensor name")
            dpg.add_separator()

            with dpg.group(horizontal=True, horizontal_spacing=120):
                dpg.add_text("Plot2 sensor:")
                dpg.add_text("Plot2 name:")
            with dpg.group(horizontal=True):
                dpg.add_combo(tag="plot2_gauge", default_value=gauges_dict["plot2_gauge"], items=entries_list, width=200, callback=gauges_callback)
                dpg.add_input_text(tag="plot2_gauge_name", default_value=gauges_dict["plot2_gauge_name"], width=200, callback=gauges_name_callback)
                dpg.add_button(tag="plot2_gauge_name_auto", label="A", callback=gauges_name_auto_button_callback)
                with dpg.tooltip(dpg.last_item()):
                    dpg.add_text("Reset sensor name")
            dpg.add_separator()

            dpg.add_spacer(height=10)
            with dpg.group(horizontal=True):

                dpg.add_text("Refresh time (ms): ")
                dpg.add_input_int(tag="refresh_time", default_value=gauges_dict["refresh_time"], width=120, step=50, min_value=50, min_clamped=True, callback=refresh_callback)
    tr = USB_send_data_thread(gauges_dict)

    dpg.setup_dearpygui()
    dpg.set_exit_callback(exit_callback)
    dpg.show_viewport()
    dpg.start_dearpygui()
    dpg.destroy_context()
