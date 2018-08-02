# 
# This program will establish a UART communication line across COM3 to the Arduino
# https://pyserial.readthedocs.io/en/latest/pyserial_api.html
# https://pyserial.readthedocs.io/en/latest/shortintro.html#opening-serial-ports

import serial
import time

# For tensorflow to import correctly, the python file must be executed from venv
#wimport tensorflow as tf
#from tensorflow import keras # tf.keras

# helper libraries
#import numpy as np
#import matplotlib.pyplot as plt
#print(tf.__version__)

#with serial.Serial('/dev/ttyUSB0', 9600, timeout = 1) as port: # Open Serial port
	#port.write(b'1600,1600,1600,1600,1600,1600\n')
	#line = port.readline()  # read '\n' terminated line

port = serial.Serial('/dev/ttyUSB1', 9600)


port.write(b'1500,1500,1500,1500,1500,1500\n')

if port.is_open:
	time.sleep(2)
	port.write(b'1600,1600,1600,1600,1600,1600\n')
	time.sleep(2)
	for x in xrange(1,10):
		line = port.readline()
		print(line)
else:
	print("Connection failed")

time.sleep(2)
port.write(b'1400,1400,1400,1400,1400,1400\n')

port.close()