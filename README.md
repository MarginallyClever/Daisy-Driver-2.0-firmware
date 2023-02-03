# Daisy-Driver-2.0-firmware
Daisy Driver 2.0 firmware

Code for the Daisy Driver 2 PCB that will be added to [Sixi 3 robot actuators](https://www.marginallyclever.com/products/mcr-gearbox-13-70-78-135-109-a-diy-kit/).

The board consists of 
- a STM32F103C8T6 MCU, 
- an IPS2200 absolute rotation induction sensor
- an TMC2130 stepper driver
- 2x CAN bus connections
- 2x power connections
- and an RGB LED

The target is a closed-loop motor driver that can be daisy chained.  Each motor is attached to a harmonic gearbox for great reduction and increased power.  

Ultimately the goal is a super low cost robot actuator with great repeatable accuracy.
