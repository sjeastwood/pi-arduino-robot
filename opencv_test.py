import cv2
import numpy as np

#Load an image from file
image = cv2.imread("face.jpg", 1)

#Load a cascade file for detecting faces
face_cascade = cv2.CascadeClassifier('/home/pi/opencv-3.4.3/data/haarcascades/haarcascade_frontalface_alt.xml')

#Convert to grayscale
gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

#Look for faces in the image using the loaded cascade file
faces = face_cascade.detectMultiScale(gray, 1.3, 5)

print ("Found "+str(len(faces))+" face(s)")

#Draw a rectangle around every found face
for (x,y,w,h) in faces:
    cv2.rectangle(image,(x,y),(x+w,y+h),(255,0,0),2)

#Save the result image
cv2.imwrite('result.jpg',image)
