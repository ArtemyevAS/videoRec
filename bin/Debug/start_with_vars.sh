#!/bin/bash

now=$(date +"%T")
echo "Current time : $now"

#this app based on OpenCV, so libraries are required
export LD_LIBRARY_PATH="/home/pi/opencvInst/lib:$LD_LIBRARY_PATH"

./videoRec 0 25 1920 1080 /home/pi/vid_720_576_$now.avi
