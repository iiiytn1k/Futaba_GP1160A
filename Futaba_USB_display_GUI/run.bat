SET PATH=%PATH%;.\venv\Lib\site-packages\usb1
IF NOT EXIST venv\ (
python -m venv .\venv
CALL .\venv\scripts\activate
pip install -r requirements.txt
) ELSE goto :launch

:launch
CALL .\venv\scripts\activate
python GUI_futaba.pyw
