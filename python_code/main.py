# Python Links
# This program will establish a UART communication line across COM3 to the Arduino
# https://pyserial.readthedocs.io/en/latest/pyserial_api.html
# https://pyserial.readthedocs.io/en/latest/shortintro.html#opening-serial-ports
# https://docs.python.org/2/library/time.html
# https://docs.python.org/2/library/signal.html

# OpenCV Python Links
# How to save frames from video object
# https://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_gui/py_video_display/py_video_display.html

# Python Tkinter GUI Links
# https://www.python-course.eu/tkinter_labels.php

# Arduino UART Links
# http://forum.arduino.cc/index.php?topic=81612.0
# https://www.arduino.cc/en/Serial/Begin


# ********** Imports *********

import numpy as np
import cv2
import serial
import time
#import Tkinter as tk
#import threading

# Robosub Created Libraries
import vid_process


# ********** Initialization to devices **********

# Initialize Tkinter GUI


# Initalize serial port connections
# (This design is outdated, based upon using two separate arduinos)
ENABLE_SERIAL  = False


if ENABLE_SERIAL:
    THRUST = serial.Serial('/dev/ttyUSB1') # This should check the system for USB devices (If the system is linux and supports lsusb) and will auto configure pyserial initialization
    IMU = serial.Serial('/dev/ttyUSB0', 115200, timeout = 1)

    # Required for proper thruster operation
    time.sleep(2)


# ********* Main Control Loop *********



# ********* Video Processing **********
vid_process.vid_test("pvf")

if ENABLE_SERIAL:
    while True:
        if IMU.is_open:
            line = IMU.readline()
            split_line = line.split(',')
            roll = cast_float(split_line[0])
            pitch = cast_float(split_line[1])
            yaw = cast_float(split_line[2])
            print(yaw)

        time.sleep(2) # This workaround messes with other sensors. Find another way to create a delay with interrupts
        set_thrusters(0,0,0,0,0,0,5)
        set_thrusters(-120,165,0,0,0,0,2) # Go down
        set_thrusters(-70,110,300,300,294,294,180) # Go forward (Different ESC's on either side)

        if cv2.waitKey(1) & 0xFF == ord('q'):
                    break



    # ******** Device and Port Release ********

    if IMU.is_open == False:
        print("Connection failed")

    IMU.close()
    THRUST.close()
    print("Serial Connection Closed")
