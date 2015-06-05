#!/usr/bin/env ipython3
# -*- coding: utf-8 -*-

### New Python Template File
### H27 Mar 16

import os, sys
import math
import numpy
import pylab


#----- calc_kishou() -----#
def calc_kishou(mag, dep, dist, d):
    dist = math.sqrt(dep**2 + dist**2)
    PGVb600 = 10**(0.58*mag + 0.0038*dep - 1.29 - math.log10(dist + 0.0028*(10**(0.50 * mag))) - 0.002*dist)
    PGVb700 = PGVb600 * 0.9
    AVS = 400
    ARV = 10**(1.83 - 0.66 * math.log10(AVS))
    PGV = PGVb700 * ARV
    intensity = 2.68 + 1.72 * math.log10(PGV)
    return intensity

#----- main() -----#
def main():
    mag = float(input('\tmag      --> '))
    dep = float(input('\tdep[km]  --> '))
    dist= float(input('\tdist[km] --> '))
    print("\tmag: {0},\tdep: {1}[km],\tdist: {2}[km]".format(mag, dep, dist))

    d_list = [0, -0.02, 0.12]
    print("\t地震のタイプを選択してください: \n\t\t[0] 地殻内地震\n\t\t[1] プレート間地震\n\t\t[2] プレート内地震")
    select = int(input('\t --> '))
    #d = d_list[select]
    if (select == 0):
        d = d_list[0]
    elif (select == 1):
        d = d_list[1]
    else:
        d = d_list[2]

    x = []
    for i in range(1, 100, 2):
        x.append(i)

    y = []
    for i in x:
        y.append(calc_kishou(mag, dep, i, d))

    #print("\n\tKishou : {0}".format(calc_kishou(mag, dep, dist, d)))
    for i in y:
        print("\t{0}".format(i))

    pylab.plot(x, y, color="k", marker="o")
    pylab.show()


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print("\nCtrl+C -> END")

