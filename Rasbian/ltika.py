#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

IO_NO = 4

print("press ^C to exit program ...\n")

GPIO.setmode(GPIO.BCM)

GPIO.setup(IO_NO, GPIO.OUT)

def main():
    while 100:
        GPIO.output(IO_NO, True)
        time.sleep(0.5)
        GPIO.output(IO_NO, False)
        time.sleep(0.5)

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print("\ndetect key interrupt")
        GPIO.cleanup()
        print("Program exit\n")
