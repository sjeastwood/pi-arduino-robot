import RPi.GPIO as gpio
import smbus
import time
import sys

bus = smbus.SMBus(1)
address = 0x04
data1 = 25
data2 = 50
data3 = 180
data4 = 90
data5 = 80
data6 = 45


def main():

    gpio.setmode(gpio.BCM)
    gpio.setup(17, gpio.OUT)
   

    gpio.output(17, 1) #turn LED on to show data being sent
    print "Sending data: ", data1
    bus.write_byte(address, data1)
    print "Arduino received first motor angle:", bus.read_byte(address)
    time.sleep(0.2)
    print "Sending data: ", data2
    bus.write_byte(address, data2)
    print "Arduino received second motor angle:", bus.read_byte(address)
    time.sleep(0.2)
    print "Sending data: ", data3
    bus.write_byte(address, data3)
    print "Arduino received third motor angle:", bus.read_byte(address)
    time.sleep(0.2)
    print "Sending data: ", data4
    bus.write_byte(address, data4)
    print "Arduino received fourth motor angle:", bus.read_byte(address)
    time.sleep(0.2)
    print "Sending data: ", data5
    bus.write_byte(address, data5)
    print "Arduino received fifth motor angle:", bus.read_byte(address)
    time.sleep(0.2)
    print "Sending data: ", data6
    bus.write_byte(address, data6)
    print "Arduino received sixth motor angle:", bus.read_byte(address)
    time.sleep(0.2)
            
    while True:
        if bus.read_byte(address) == 1:
            print "Arduino is done receiving data"
            gpio.output(17,0) #turn LED off to show data was sent
            gpio.cleanup()
            break
    time.sleep(1)

    


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print 'Interrupted'
        gpio.cleanup()
        sys.exit(0)
