#!/usr/bin/env python

import pygame
from pygame.locals import *
import time
import decimal


def slices(axis):
    if (axis[0] == '-'):
        axis = '-' + axis[1:4]
    else:
        axis = '+' + axis[0:3]
    if (axis == "+0.0"):
        axis = "0.0"
    return axis


def main():
    while True:
        pygame.joystick.init()
        joys = pygame.joystick.Joystick(0)
        joys.init()
        pygame.init()

        eventlist = pygame.event.get()
        eventlist = filter(lambda e : e.type == pygame.locals.JOYBUTTONDOWN, eventlist)
    
        axis_x = slices(str(joys.get_axis(0)))
        axis_y = slices(str(joys.get_axis(1)))

        if (axis_y[0] == '-'):
            axis_y = '+' + axis_y[1:4]
        elif (axis_y[0] == '+'):
            axis_y = '-' + axis_y[1:4]

        axises = [axis_x, axis_y]
    
        print(axises)
        time.sleep(0.1)


if __name__ == '__main__':
    try:
        main()
    except pygame.error:
        print ("Please connect Device")
    except KeyboardInterrupt:
        print("\ndetect key interrupt")

