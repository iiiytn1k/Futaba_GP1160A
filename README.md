## Futaba GP1160AI (GP1160A02A) USB Display Driver

[Описание на русском](README.ru.md)

![](https://github.com/iiiytn1k/Futaba_GP1160A/blob/master/KDPV.jpg?raw=true)


### Futaba_USB_display_GUI

A python program sends the captured screen over USB to the STM32F401CxU6 microcontroller, then that data is displayed on the VFD with selected colors pallete.

How to use:  
1. Flash MCU with the required firmware (4 or 8 colors, single or dual display mode). VS Code with PlatformIO extension is recommended for compiling firmware and flashing MCU
2. Connect display to the MCU according to [wiring diagram](https://github.com/iiiytn1k/Futaba_GP1160A/blob/master/Connection.png?raw=true)
3. Connect the MCU to your PC. Drivers will be installed automatically
4. Connect external 5V power to the display. Display should show a splash screen, as in the picture above
5. Run ```Run.bat```. At the first start, a ```venv``` folder will be created in the program directory, in which all the required python modules will be installed
6. After starting the program, click the «Connect» button. If everything went well, instead of the «Connect» button message "Connected" will be appear, and the firmware type will be displayed in the line below. You can check USB connection is working well by changing the display brigthness («Display brightness» slider)
7. Click the «Run» button. When you first start the program, the captured image will be displayed on the display after a few seconds
8. Adjust image parameters — position and size of the capture area, dithering algorithm, brightness/contrast/gamma


### Futaba_USB_hardware_monitor_GUI

A simple hardware monitor. Works with MSI Afterburner

How to use:
1. Follow steps 1-4 from [section above](#futaba_usb_display_gui)
2. Download, install and run [MSI Afterburner](https://www.msi.com/Landing/afterburner/graphics-cards)
3. Run ```Run.bat```
4. Select the required sensors

### Requirements 
1. Any STM32F401CCU6 or STM32F401CDU6 board, like [Black Pill](https://stm32-base.org/boards/STM32F401CCU6-WeAct-Black-Pill-V1.2) or [STM32 Mini F401 (HW-848)](https://stm32-base.org/boards/STM32F401CCU6-STM32-Mini-F401)
32. Python 3.9 or above

### Demo:
![](https://img.shields.io/badge/-youtube?logo=youtube&style=social)[【東方】Bad Apple!! on Futaba GP1160A02A](https://youtu.be/tSLnOEqLiwY)

![](https://img.shields.io/badge/-youtube?logo=youtube&style=social)[Futaba GP1160AI (GP1160A02A) 8 Colors Dual Mode. Doom II — MAP01. Финальный результат.](https://youtu.be/7nB765_jwOM)

[Hardware Monitor](https://github.com/iiiytn1k/Futaba_GP1160A/blob/master/hm.jpg?raw=true)
