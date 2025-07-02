import serial
import pyautogui

ser = serial.Serial('COM5', 115200)  # Change to your port!

try:
    while True:
        if ser.in_waiting:
            line = ser.readline().decode().strip()
            
            if line == "VOL_DOWN":
                pyautogui.press('volumedown')
                print("Volume Down")
                
            elif line == "VOL_UP":
                pyautogui.press('volumeup')
                print("Volume Up")
                
except KeyboardInterrupt:
    ser.close()