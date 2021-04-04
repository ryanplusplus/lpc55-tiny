Overview
========
The purpose of this demo is to show wakeup from deep sleep mode using MicroTick timer.
The demo sets the MicroTick Timer as a wake up source and puts the device in deep-sleep mode. 
The MicroTick timer wakes up the device. 

Toolchain supported
===================
- IAR embedded Workbench  8.50.5
- Keil MDK  5.31
- GCC ARM Embedded  9.2.1
- MCUXpresso  11.2.0

Hardware requirements
=====================
- Micro USB cable
- LPCXpresso55S16 board
- Personal Computer

Board settings
==============
1. J13-1(PIO0_16) is used as a CLKOUT signal. Connect this pin to an Oscilloscope for viewing the signal. 
The jumper setting:
    Default jumpers configuration does not work,  you will need to add JP20 and JP21 (JP22 optional for ADC use)

Running the demo
================
The demo sets the MicroTick Timer as a wake up source and puts the device in sleep mode. 
The MicroTick timer wakes up the device.

 After wake up：

(1)the red LED on the board blinking. 
(2)CLKOUT signal changing can be seen on J13-1. And the frequency of output signal will double.

If the demo run successfully, you will see the log from debug console:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Utick wakeup demo start...
Wakeup from sleep mode...

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
