#Ground Control Arcade Joystick 

This code allows for the usage of any ATmega32u4-based device (such as the "Arduino Leonardo") as a native USB joystick.
It was originally contributed by Kevin Peat and modified for the "Ground Control" arcade project.

In order to use this code, you have to install the modified version of the '''USBAPI.h''' and '''HID.cpp''' files.
These files have to be copied to the directory '''hardware/arduino/cores/arduino''' in the path where your Arduino installation is.

For instructions on how to wire the joystick, [follow this wiki page](http://www.samuraicircuits.com/MediaWiki/index.php?title=Ground_Control_Arcade_Box). 

This code has been tested on Arduino Leonardo and PRO Micro boards using the v.1.0 of the Arduino IDE.

##TODO

- Support Arduino IDE >= 1.6
- Speed hacks: responsivity is already really good, but it can be improved

##Changelog

06/10/2016 - Fixed HID and USBAPI files
03/23/2014 - Fixed USB HID descriptor for the Ground Control joystick (16 buttons, 2 axes)
12/10/2013 - First release of Ground Control Arcade controller
