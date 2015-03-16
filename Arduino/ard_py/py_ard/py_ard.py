#!/usr/bin/env python


import serial
import time


ard = serial.Serial('/dev/ttyUSB0', 9600)


def flash(mes):
    for i in range(10):
        for i in range(50):
            ard.write(mes)
        time.sleep(0.2)


time.sleep(2)
flash('f')
flash('b')
flash('r')
flash('l')
