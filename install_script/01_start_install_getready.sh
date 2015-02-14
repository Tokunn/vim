#!/usr/bin/env sh

systemctl enable dhcpcd.service

pacman -Syu --noconfirm
pacman -S git python2 python3 --noconfirm

./02_start_install.py
