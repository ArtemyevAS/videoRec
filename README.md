# videoRec
This is a small command line utility for recording video streams from camera or any other source to file with H.264 codec.
May be built on ARM and x86.

Usage: uitility_name DEVNO FPS WIDTH HEIGHT PATH_OUTPUT_FILE

DEVNO - device number, may be found on /dev
FPS - frame per second for target file - 25
WIDTH , HEIGHT - dimensions
PATH - full file path

Ater start utility opens preview window.

Binary at /bin directory is for v7 ARM

You need OpenCV (www.opencv.org) to build this code.
