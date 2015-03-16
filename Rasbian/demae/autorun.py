#!/usr/bin/env python

import pygame
import subprocess
from pygame.locals import *
import time
import decimal
import RPi.GPIO as GPIO

def PinSet():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(18, GPIO.OUT)


def slices(axis):
    if (axis[0] == '-'):
        axis = '-' + axis[1:4]
    else:
        axis = '+' + axis[0:3]
    if (axis == "+0.0"):
        axis = "0.0"
    return axis


def main():

    PinSet()

    comm = "sudo shutdown -h now".split()

    while True:
        pygame.joystick.init()
        if (pygame.joystick.get_count() == 0):
            print ("\nPlease connect Device")
            return(-1)

        joys = pygame.joystick.Joystick(0)
        joys.init()
        pygame.init()
       
        eventlist = pygame.event.get()
    
        axis_lx = slices(str(joys.get_axis(0)))
        axis_ly = slices(str(joys.get_axis(1)*-1))
        axis_rx = slices(str(joys.get_axis(2)))
        axis_ry = slices(str(joys.get_axis(3)*-1))

        hat = joys.get_hat(0)

        but_x = joys.get_button(0) 
        but_a = joys.get_button(1)
        but_b = joys.get_button(2)
        but_y = joys.get_button(3)
        but_lb = joys.get_button(4)
        but_rb = joys.get_button(5)
        but_lt = joys.get_button(6)
        but_rt = joys.get_button(7)
        but_back = joys.get_button(8)
        but_start = joys.get_button(9)
        but_joypush_l = joys.get_button(10)
        but_joypush_r = joys.get_button(11)

        axises = [axis_lx, axis_ly, axis_rx, axis_ry]
        buttons = [hat, but_x, but_a, but_b, but_y, but_lb, but_rb, but_lt, but_rt, but_back, but_start]
        
        if (but_x == 1):
            GPIO.output(18, True)
        if (but_y == 1):
            GPIO.output(18, False)

        print(axises)
        print(buttons)

        if (but_back==1) and (but_start==1) and (but_joypush_l==1) and (but_joypush_r==1):
            #subprocess.call(comm)
            return(0)

        time.sleep(0.1)



if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print ("\nexit program \(^o^)/")

    print ("\nStop reading (((o(*'-' *)o)))\n")
