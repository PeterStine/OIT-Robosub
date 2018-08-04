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

# ********** Functions **********
def cast_float(n):
	try:
		return float(n)
	except ValueError:
		return float(0)

def set_thrusters(a,b,c,d,e,f,delay):
	print("Use time.time()")

def set_thrusters_DEPRECATED(a,b,c,d,e,f,delay):
        # Jay Sucharitakul
        seconds = 11 # Initial time must be the time+1 (now 10+1)
        timer = None

        seconds -= 1
        if seconds==0:
                # Peter's code
                line = str(1500 + a) + b',' + str(1500 + b) + b',' + str(1500 + c) + b',' + str(1500 + d) + b',' + str(1500 + e) + b',' + str(1500 + f) + b'\n'
                THRUST.write(line)
                seconds = 10
        timer = threading.Timer(1, tick)
        timer.start()

        
        
	# Concatenate values relative to stationary
	#line = str(1500 + a) + b',' + str(1500 + b) + b',' + str(1500 + c) + b',' + str(1500 + d) + b',' + str(1500 + e) + b',' + str(1500 + f) + b'\n'
	#THRUST.write(line)

	#time.sleep(delay)
	
def tprint(string):
        print("Unfinished")

# ********** Imports *********

import numpy as np
import cv2
import serial
import time
import Tkinter as tk
import threading


# ********** Initialization to devices **********

# Initialize GUI


# Initalize serial port connections
THRUST = serial.Serial('/dev/ttyUSB1')
IMU = serial.Serial('/dev/ttyUSB0', 115200, timeout = 1)

# Required for proper thruster operation
time.sleep(2)


# ********* Main Control Loop *********

while True:
	if IMU.is_open:
		line = IMU.readline()
		split_line = line.split(',')
		roll = cast_float(split_line[0])
		pitch = cast_float(split_line[1])
		yaw = cast_float(split_line[2])
		print(yaw)

	#time.sleep(2) # This workaround messes with other sensors. Find another way to create a delay with interrupts
	#set_thrusters(0,0,0,0,0,0,5)
	#set_thrusters(-120,165,0,0,0,0,2) # Go down 
	#set_thrusters(-70,110,300,300,294,294,180) # Go forward (Different ESC's on either side)

	if cv2.waitKey(1) & 0xFF == ord('q'):
                break


cap = cv2.VideoCapture(1)

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret==True:
    

        frame = cv2.flip(frame,0)

        # write the flipped frame
        out.write(frame)

        cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break


# ******** Device and Port Release ********

# Release everything if job is finished
cap.release()
out.release()
cv2.destroyAllWindows()

if IMU.is_open == False:
	print("Connection failed")

IMU.close()
THRUST.close()
print("Serial Connection Closed")
