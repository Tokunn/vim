#!/usr/bin/env python


import serial
import time

xbeeport = "/dev/ttyUSB0"
ardport = "/dev/ttyACM1"


def main():

  #xbeeport = raw_input("xbee-Port :")
  #ardport = raw_input("ard-Port :")

  xbee = serial.Serial(xbeeport, 9600) 
  ard = serial.Serial(ardport, 9600)

  while True:
    mes = xbee.readline()
    ard.write(mes)
    print(mes)



if __name__ == '__main__':
  main()
