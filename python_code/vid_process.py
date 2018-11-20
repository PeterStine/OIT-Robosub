# This file is intended to process images from the camera input.


# Opencv code

import numpy as np
import cv2

MODE = input("Specify mode: ")

# Record Video Input Mode
if MODE == "rvi":

    cap = cv2.VideoCapture(0)

    # Define the codec and create VideoWriter objectsd
    fourcc = cv2.VideoWriter_fourcc(*'XVID')

    # Be careful using the following method of file writing, it will overwrite last file
    out = cv2.VideoWriter('output.xvid', fourcc, 20.0, (640, 480))

    while (cap.isOpened()):
        ret, frame = cap.read()

        if ret == True:
            out.write(frame)
            frame = cv2.rectangle(frame,(35,25),(340,45),(0,0,0),-1)
            frame = cv2.putText(frame,'Record Video Input Mode',(40,40),cv2.FONT_HERSHEY_PLAIN,1,(0,255,0),1,cv2.LINE_AA)


            cv2.imshow('frame', frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        else:
            break

    out.release()

# Play Video File Mode
elif MODE == "pvf":
    cap = cv2.VideoCapture('output.xvid')

    while (cap.isOpened()):
        ret, frame = cap.read()
        frame = cv2.putText(frame, 'Playback Video File Mode', (40, 40), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 2,cv2.LINE_AA)
        cv2.imshow('frame', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
else:
    print("Invalid Input")

cap.release()
cv2.destroyAllWindows()