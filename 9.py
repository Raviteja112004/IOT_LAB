import serial
import time
from datetime import datetime

ser = serial.Serial('COM9', 9600)  # Replace with your Arduino port
time.sleep(2)  # Wait for Arduino to reset

while True:
    now = datetime.now()
    current_time = now.strftime("%d-%m-%Y %H:%M:%S\n")
    ser.write(current_time.encode())
    print("Sent:", current_time.strip())
    time.sleep(1)