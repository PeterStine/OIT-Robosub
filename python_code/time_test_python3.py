import time

initial_time = time.time()

while True:
	timer = time.time()
	timer = initial_time - timer
	if timer > 10:
		print("10 seconds")
		print(timer)
