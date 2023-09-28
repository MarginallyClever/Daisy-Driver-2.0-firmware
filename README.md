# Daisy-Driver-2.0-firmware

Daisy Driver 2.0 is a low cost robot actuator with great repeatable accuracy.  It is good for compliant systems, 3D printers, actuators, and more.
It provids a closed-loop motor driver that can be daisy chained.  Shorter wiring, easier maintenance, lower cost of failure.

# What's on the board

- a STM32F405RGT6 MCU (168Mhz, 1 Mbyte memory), 
- an IPS2200 absolute rotation induction sensor (12 bits aka 4096 positions, 0.087890625deg/step)
- an TMC2130 stepper driver (SilentStep, bump sensing)
- 2x CAN bus connections
- 2x power connections
- 1x USB connection
- and an RGB LED

# Use cases

Code for the Daisy Driver 2 PCB that will be added to [Sixi 3 robot actuators](https://www.marginallyclever.com/products/mcr-gearbox-13-70-78-135-109-a-diy-kit/).
It may also appear in future versions of the world-famous [Makelangelo polargraph robot](makelangelo.com)

# Firmware

This code lives in both the root node (CAN bus address 0) and the clients (CAN bus address != 0).  
It provides a serial USB Gcode interface so that it behaves like any traditional CNC machine.
