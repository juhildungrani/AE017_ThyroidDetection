import serial
import time

ser = serial.Serial('COM3',9600,timeout=0.1)
ser.setDTR(False)
ser.close()

def sendSerial(data):
    ser.open()
    time.sleep(0.5)
    ser.write(data)
    time.sleep(0.5)
    ser.close()
