import threading

seconds = 1 # Initial time must be the time+1 (now 0+1)
timer = None

def tick ():
    global seconds, timer
    seconds -= 1
    if seconds==0:
        print("%i seconds left" % seconds)
        print("Timer expired!")
        seconds = 10
    # printing here will mess up your stdout in conjunction with input()
    print("%i second(s) left" % seconds)
    timer = threading.Timer(1, tick)
    timer.start()

seconds += 10
tick()
