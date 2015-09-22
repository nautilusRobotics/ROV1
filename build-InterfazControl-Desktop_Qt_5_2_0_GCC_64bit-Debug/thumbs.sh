#!/bin/bash
mplayer -vo png -frames 1 $1
mv 00000001.png  $1.thumb
