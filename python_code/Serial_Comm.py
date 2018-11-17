# This file will contain all functions that utilize pyserial and control thrusters.

# All of the following functions need function description headers.
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

# What is tprint supposed to be?
def tprint(string):
        print("Unfinished")


