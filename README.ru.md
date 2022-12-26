## Futaba GP1160AI (GP1160A02A) USB Display Driver

![](https://github.com/iiiytn1k/Futaba_GP1160A/blob/master/KDPV.jpg?raw=true)


### Futaba_USB_display_GUI

Python-программа, которая захватывает область экрана, делает все необходимые преобразования и передаёт полученное изображение по USB в микроконтроллер STM32F401CxU6, который затем отображает захваченную область на ВЛИ-дисплее Futaba GP1160AI.

Порядок использования:  
1. Скомпилируйте нужную версию прошивки (4 или 8 цветов, один или два дисплея) и прошейте микроконтроллер. Для компилирования и прошивки рекомендуется использовать Visual Studio Code с дополнением PlatformIO
2. Подключите дисплей к микроконтроллеру в соответствии со [схемой подключения](https://github.com/iiiytn1k/Futaba_GP1160A/blob/master/Connection.png?raw=true)
3. Подключите микроконтроллер к любому USB порту компьютера. Драйвер должен установится автоматически
4. Подключите внешнее питание 5В к дисплею. На дисплее должен отобразиться сплеш-скрин, как на фотографии выше
5. Запустите ```Run.bat```. При первом запуске в каталоге программы будет создана папка venv, в которую установятся все необходимые модули python
6. После запуска программы нажмите кнопку «Connect­­». Если все прошло успешно, то вместо кнопки Connect появится сообщение "Connected", а строкой ниже отобразится тип прошивки. Работоспособность соединения можно проверить путем изменения яркости дисплея (ползунок Display brightness)
7. Нажмите кнопку «Run­». При первом запуске программы захваченное изображение отобразится на дисплее спустя несколько секунд
8. Настройте параметры изображения — положение и размер области захвата, алгоритм дизеринга, яркость/контрастность/гамму

### Futaba_USB_hardware_monitor_GUI

Простой монитор ресурсов компьютера. Работает в связке с MSI Afterburner

Порядок использования:  
1. Выполните пункты 1-4 из [раздела выше](#futaba_usb_display_gui)
2. Скачайте, установите и запустите [MSI Afterburner](https://www.msi.com/Landing/afterburner/graphics-cards)
3. Запустите ```Run.bat```
4. Выберите необходимые датчики для отображения на дисплее

### Требования
1. Любая плата с микроконтроллером STM32F401CCU6 или STM32F401CDU6. Эти платы известны под именами [Black Pill](https://stm32-base.org/boards/STM32F401CCU6-WeAct-Black-Pill-V1.2) и [STM32 Mini F401 (HW-848)](https://stm32-base.org/boards/STM32F401CCU6-STM32-Mini-F401)
2. Python версии 3.9 и выше

### Демо:
![](https://img.shields.io/badge/-youtube?logo=youtube&style=social)[????Bad Apple!! on Futaba GP1160A02A](https://youtu.be/tSLnOEqLiwY)

![](https://img.shields.io/badge/-youtube?logo=youtube&style=social)[Futaba GP1160AI (GP1160A02A) 8 Colors Dual Mode. Doom II — MAP01. Финальный результат.](https://youtu.be/7nB765_jwOM)

[Hardware Monitor](https://github.com/iiiytn1k/Futaba_GP1160A/blob/master/hm.jpg?raw=true)