#!/usr/bin/env python

import sys, os
import subprocess

gui_config = """
Section "InputClass"
    Identifier      "Keyboard Defaults"
    MatchIsKeyboard "yes"
    Optiion         "XkbLayout" "jp"
EndSection
"""
lxde = """
exec startlxde
"""

def call_system(cmd):
    splitted_cmd = cmd.split()
    subprocess.call(splitted_cmd)

def install(soft):
    cmd = "pacman -S {0} --noconfirm".format(soft)
    call_system(cmd)

def main():

    print("#1 System update")
    call_system("pacman -Syu --noconfirm")

    print("#2 Install")
    software = ['vim', 'tmux', 'sudo', 'visudo', 'traceroute', 'nmap', 'gdb', 'wireshark-gtk', 'net-tools', 'wget', 'otf-ipafont', 'python2-pyserial', 'vim-systemd', 'python2-pygame', 'openssh']
    for i in range(len(software)):
        print(software[i])
        install(software[i])

    print("#3 Add New User")
    print("Do you want to add new users? [Y/n]")
    yorn = input('-->')
    if ((yorn == 'y') or (yorn == 'Y')):
        print("Type usernaem")
        username = input('-->')
        call_system("useradd -m -g users -G wheel -s /bin/bash {0}".format(username))
        print("Set password")
        call_system("passwd {0}".format(username))

    print("#4 Install GUI")
    software = ['xorg-server', 'xorg-server-utils', 'xorg-xinit', 'mesa', 'xf86-video-fbdev', 'xf86-input-synaptics', 'lxde', 'awesome']
    for i in range(len(software)):
        print(software[i])
        install(software[i])
    f = open('/etc/X11/xorg.conf.d/10-keyboard.conf', 'w')
    f.write(gui_config)
    f.close()
    f = open('../../../.xinitrc', 'w')
    f.write(lxde)
    f.close()

if __name__ == '__main__':
    main()
