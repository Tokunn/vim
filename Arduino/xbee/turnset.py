#!/usr/bin/env python


import serial


class OpenSerial(object):

  def __init__(self, port):
    self.xbee = serial.Serial(port, 9600)

  def turnup(self, com):
    for i in range(1000):
      self.xbee.write(com)


def main():

  port = raw_input("Port :")
  ard = OpenSerial(port)

  while True:
    com = raw_input("Please type command :")
    if (len(com) > 3):
      print("BaaaaKA")
      break
    ard.turnup(com)


if __name__ == '__main__':
  main()
