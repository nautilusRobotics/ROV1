#!/bin/bash
mplayer -vo png:z=0 -vc ffh264 -frames 1 $1 -msglevel all=-1
mv 00000001.png  $2
