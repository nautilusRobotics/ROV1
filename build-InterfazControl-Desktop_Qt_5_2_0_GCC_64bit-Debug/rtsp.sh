#!/bin/bash
openRTSP -4 -f 20 -w 2048 -h 1536 -b 300000 rtsp://admin:12345@10.5.5.110:554  > ./Missions/$1/vid_$2.mp4
