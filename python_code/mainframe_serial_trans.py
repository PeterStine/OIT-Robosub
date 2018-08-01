# 
# This program will establish a UART communication line across COM3 to the Arduino
# https://pyserial.readthedocs.io/en/latest/pyserial_api.html
# https://pyserial.readthedocs.io/en/latest/shortintro.html#opening-serial-ports

import serial

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

port = serial.Serial('/dev/ttyUSB1')

if port.is_open == False:
	port = serial.Serial('/dev/ttyUSB1') 
else:
	print("USB0 and USB1 Failed to open")

print(port.name)

port.baudrate = 115200

if port.is_open:
	
	print("Connection opened")
	start = "Failure"
	start = port.readline(50)
	
	print(start)
	port.write(b'<1600,1600,1600,1600,1600,1600>')

else:
	print("Connection failed")

port.close()