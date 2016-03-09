#!/bin/bash
TMP="tmp.png"
TMP_VID=$1/vid.mp4
openRTSP -4 -f 30 -w 1920 -h 1080 -b 300000 -d 0.2 -V rtsp://admin:12345@10.5.5.110:554  > $TMP_VID
ffmpeg -i $TMP_VID  -t 1 -f image2 $TMP 
mv $TMP $1/$2
#rm $TMP_VID
