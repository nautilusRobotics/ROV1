#!/usr/bin/env python

from pyA20.gpio import gpio
from pyA20.gpio import port
from pyA20.gpio import connector
from time import sleep


gpio.init()
gpio.setcfg(port.PI0,gpio.OUTPUT)
gpio.pullup(port.PI0,gpio.PULLUP)

gpio.output(port.PI0,gpio.HIGH)
sleep(0.1)
gpio.output(port.PI0,gpio.LOW)
