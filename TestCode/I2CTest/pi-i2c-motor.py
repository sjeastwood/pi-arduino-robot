import RPi.GPIO as gpio
import smbus
import time
import sys

bus = smbus.SMBus(1)
address = 0x04
data = "10,20"


def main():

    gpio.setmode(gpio.BCM)
    gpio.setup(17, gpio.OUT)
   
    while 1:
            gpio.output(17, 1) #turn LED on to show data being sent
            print "Sending data: ", data
            bus.write_byte(address, data)
            print "Arduino answer to rPi:", bus.read_byte(address)
            gpio.output(17,0) #turn LED off to show data was sent
            time.sleep(1)

    return


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print 'Interrupted'
        gpio.cleanup()
        sys.exit(0)
