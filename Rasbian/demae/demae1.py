#!/usr/bin/env python2

import time
import math
import serial
import pygame
import decimal
import subprocess
import get_gamepad
#import RPi.GPIO as GPIO
from pygame.locals import *


class SendSerial():
    
    def __init__(self, port):
        self.ard = serial.Serial(port, 9600)

    def sendserial(self, com):
        self.ard.write(com)


def PinSet():
    pass
    #GPIO.setmode(GPIO.BCM)
    #GPIO.setup(18, GPIO.OUT)


def shutdown_check(command):
    if (command[0]+command[1] == 2):
        return(1)


def robot_updown():
    #GPIO.output(18, True)
    time.sleep(0.1)
    #GPIO.output(18, False)


def make_aru_com(F710, types):
    aru_com = ['s', 0, 'n', 0]

    if (types == 'tire'):
        Axis_Y = F710.left_Axis_Y
        Axis_X = F710.left_Axis_X
    elif (types == 'cata'):
        Axis_Y = F710.rigt_Axis_Y
        Axis_X = F710.rigt_Axis_X

    if (Axis_Y > 0):
        aru_com[0] = 'f'
    elif (Axis_Y < 0):
        aru_com[0] = 'b'
    else:
        aru_com[0] = 's'

    if (Axis_X > 0):
        aru_com[2] = 'r'
    elif (Axis_X < 0):
        aru_com[2] = 'l'
    else:
        aru_com[2] = 'n'

    aru_com[1] = int(math.fabs(round(Axis_Y*10)))
    aru_com[3] = int(math.fabs(round(Axis_X*10)))

    return aru_com



def main():

    port_left = ''
    port_rigt = ''

    F710 = get_gamepad.LogicoolGamepad()
    PinSet()
    ard_left = SendSerial(port_left)
    ard_rigt = SendSerial(port_rigt)


    while True:
        F710.update()

        if (F710.Button_X):
            robot_updown()

        ard_tire_com = make_ard_com(F710, 'tire')
        ard_cata_com = make_ard_com(F710, 'cata')
        ard_left.sendserial(ard_tire_com)
        ard_rigt.sendserial(ard_tire_com)

        if (shutdown_check([F710.Button_Back, F710.Button_Strt])): return 0
        time.sleep(0.05)





if __name__ == '__main__':
    try:
        main()

    except get_gamepad.GamepadError:
        print("\nGamepadDevice not found !!")
        print("Please connect GamepadDevice\n")

    except KeyboardInterrupt:
        print("\nexit q(-_-)")
        quit

    subprocess.call("sudo shutdown -h now".split())
