#!/usr/bin/env python

import time
import pygame
import decimal
import subprocess
from pygame.locals import *


def slice_axis(axis):   #slice axis
    if (axis[0] == '-'):
        axis = axis[0:4]
    else:
        axis = '+' + axis[0:3]
    if (axis == "+0.0") or (axis == "-0.0"):    #zero check
        axis = "0.0"
    return axis


def main():

    pygame.joystick.init()
    pygame.init()

    if (pygame.joystick.get_count() == 0):
        print ("\nPlease connect Device")
        return(-1)

    while True:

        joys = pygame.joystick.Joystick(0)
        joys.init()
       
        eventlist = pygame.event.get()
    
        axis_lx = slice_axis(str(joys.get_axis(0)))
        axis_ly = slice_axis(str(joys.get_axis(1)*-1))
        axis_rx = slice_axis(str(joys.get_axis(2)))
        axis_ry = slice_axis(str(joys.get_axis(3)*-1))

        hat = joys.get_hat(0)

        but_x = joys.get_button(0) 
        but_a = joys.get_button(1)
        but_b = joys.get_button(2)
        but_y = joys.get_button(3)
        but_lb = joys.get_button(4)
        but_rb = joys.get_button(5)
        but_lt = joys.get_button(6)
        but_rt = joys.get_button(7)
        but_bk = joys.get_button(8)
        but_st = joys.get_button(9)
        but_joypush_l = joys.get_button(10)
        but_joypush_r = joys.get_button(11)


        if (but_bk==1) and (but_st==1) and (but_joypush_l==1) and (but_joypush_r==1):   #shutdown check
            return(0)

        time.sleep(0.1)



if __name__ == '__main__':

    print("\nb('V' .)Start!!")

    try:
        main()
    except KeyboardInterrupt:
        print ("\nexit program \(^o^)/")

    print ("\nStop reading (((o(*'-' *)o)))\n")
    comm = "sudo shutdown -h now".split()
    subprocess.call(comm) #shutdown
