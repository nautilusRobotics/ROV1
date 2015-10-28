#!/bin/bash
TMP=tmp
TMP_VID=$1/vid.mp4
openRTSP -4 -f 30 -w 1280 -h 720 -b 300000 -d 0.1 -V rtsp://admin:12345@10.5.5.110:554  > $TMP_VID
mplayer $TMP_VID -vo png:z=9:prefix=$TMP -frames 1 -msglevel all=-1
mv $TMP'00000001'.png "$1/$2"
rm $TMP_VID
