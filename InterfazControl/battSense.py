#!/usr/bin/env python

from pyA20 import i2c

i2c.init("/dev/i2c-0") #Initialize module to use /dev/i2c-0
res = i2c.open(0x20) #The slave device address is 0x2A


i2c.write([0x21]) #Set address at 0x21 ADCL register
value = i2c.read(1) #Read 1 byte
valueL=[hex(x) for x in value]

i2c.write([0x20]) #Set address at 0x20 ADCH register
value = i2c.read(1) #Read 1 
valueH=[int(x) for x in value]

total=int(valueL[0],16)+(valueH[0]<<8)
voltage=(total+3.737611)/76.250833
percentage=round((100*(voltage-10.4))/2.2)
percentage=100 if percentage>100 else percentage
percentage=0 if percentage<0 else percentage
print str(percentage)


i2c.close() #End communication with slave device

