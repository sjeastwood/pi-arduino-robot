# Pi Arduino Robot

## Overview
Code for a Raspberry Pi intereacting with six servo motors attached to an arduino.
Current test code using USB Serial interface to send motor angles of rotation separated by commas.

An alternative way using the I2C bus was used to send angle inputs one at a timeand have the Arduino code store it into an array. 

Both Serial and I2C seem viable although I2C has some quirks in terms of timing issues when adding in print statements for debugging. The bus gets hogged and data can not be sent/retreived. Serial is more simple and seems more stable in terms of awaiting for a ready signal by Arduino when it has completed the motor rotations.

## Current Progress

Code building blocks for motor control is down. OpenCV will be investigated later after manual robot control is done. 

Physical construction is the present focus

### Working on

**Physical Construction**

Will be built using an acquired aluminum Robotic Arm from Ebay consisting of motor brackets, and a clamp claw. Six servo motors are used for six degrees of freedom. 

**Materials**


- Robot arm brackets
- 6 Servo motors MG 996R
- Joystick will manual control servo motor rotation (left to right, or up and down depending on the orientation - trying to make it intuitive)
- 2 Push buttons will select the next or previous motor in the sequence.
- 2 Push buttons will select course or fine adjustments of the selected motor.
- Pushing on the Joystick will initiate the final motor for grabbing with the claw.
- LCD screen will display current motor selected.



### Planned Robot Stages

1. Manually moving robot by providing angle of rotation to the motors through python script on raspberry pi

2. Utilising keyboard and/or joystick + buttons for moving and selecting of motors

3. Using OpenCV to automate Robot

## Author
Shane Eastwood
