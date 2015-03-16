#coding: UTF-8


import serial
import time


ard = serial.Serial('/dev/ttyACM1', 9600)

time.sleep(2)

for i in range(19):
    ard.write('0')
    ard.write('1')

    time.sleep(2)

    ard.write('0')
    ard.write('2')

    time.sleep(2)

ard.close()
