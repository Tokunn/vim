#!/usr/bin/env python2


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

def get_action_axis(joys):  #Get AnalogPad data
    left_X = slice_axis(str(joys.get_axis(0)))
    left_Y = slice_axis(str(joys.get_axis(1)*-1))
    right_X = slice_axis(str(joys.get_axis(2)))
    right_Y = slice_axis(str(joys.get_axis(3)*-1))
    return [left_X, left_Y, right_X, right_Y]   #Return Left_X, Left_Y, Right_X, Right_Y

def get_action_hat(joys):   #Get Hat data
    hat_X = joys.get_hat(0)[0]
    hat_Y = joys.get_hat(0)[1]
    return [hat_X, hat_Y]   #Return Hat_X, Hat_Y

def get_action_ABXY(joys):  #Get ABXYButton data
    but_X = joys.get_button(0)
    but_A = joys.get_button(1)
    but_B = joys.get_button(2)
    but_Y = joys.get_button(3)
    return [but_A, but_B, but_X, but_Y] #Return ButtonA, ButtonB, ButtonX, ButtonY

def get_action_hide(joys):  #Get hide buttons data
    left_B = joys.get_button(4)
    right_B = joys.get_button(5)
    left_T = joys.get_button(6)
    right_T = joys.get_button(7)
    return [left_B, right_B, left_T, right_T]   #Return LeftB, RightB, LeftT, RightT

def get_action_comm(joys):  #Get command button data
    back = joys.get_button(8)
    start = joys.get_button(9)
    left_psh = joys.get_button(10)
    right_psh = joys.get_button(11)
    return [back, start, left_psh, right_psh]

def comm_check(comm):   #Check shutdown comm
    if (comm[0]+comm[1]+comm[2]+comm[3] == 4):
        return(1)


def main():
    print("\nb('v' .)Start!!")
    pygame.joystick.init()
    pygame.init()

    if (pygame.joystick.get_count() == 0):
        print ("\nPlease connect Device")
        return(-1)

    while True:
        joys = pygame.joystick.Joystick(0)
        joys.init()
        eventlist = pygame.event.get()

        axis = get_action_axis(joys)
        hat = get_action_hat(joys)
        ten = get_action_ABXY(joys)
        hide = get_action_hide(joys)
        comm = get_action_comm(joys)

        if (comm_check(comm)):
            return(0)
        time.sleep(0.1)


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print("\nInput ctrl+C q('-')") 
    print("\nexit program (((o(*'-' *).)))\n")
    subprocess.call("sudo shutdown -h now".split())
