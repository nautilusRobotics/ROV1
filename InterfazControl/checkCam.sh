#!/bin/bash
ping -q -c1 -w 1 10.5.5.110 > /dev/null
 
if [ $? -eq 0 ]; then
     echo "live"
else 
     echo "die"
fi
