#!/bin/bash
mplayer -vo png -vc ffh264 -frames 1 $1
mv 00000001.png  $1.thumb
