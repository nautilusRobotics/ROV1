#!/bin/bash
openRTSP -4 -f 30 -w 1280 -h 720 -b 300000 -V rtsp://admin:12345@10.5.5.110:554  > /mnt/disk1/NautilusOne/Missions/$1/vid_$2.mp4
