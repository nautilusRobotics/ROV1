#!/bin/bash
openRTSP -4 -f 30 -w 1920 -h 1080 -b 300000 -d 0.1 -V rtsp://admin:12345@10.5.5.110:554  > $1
