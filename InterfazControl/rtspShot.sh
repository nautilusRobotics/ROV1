#!/bin/bash
TMP_VID=$1/$2
openRTSP -4 -f 30 -w 1920 -h 1080 -b 300000 -d 0.08 -V rtsp://admin:12345@10.5.5.110:554  > $TMP_VID
