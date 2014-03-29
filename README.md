#Ground Control Arcade Joystick 

This code allows for the usage of an Arduino Leonardo as a USB joystick.
It was contributed by Kevin Peat and modified for the Ground Control arcade project.

In order to use this code, you have to install modified version of the USBAPI.h and HID.cpp files. [Follow this link for instructions](http://www.imaginaryindustries.com/blog/?p=80). Use the files I provided in this repo, however.

For instructions on how to wire the joystick, [follow this wiki page](http://www.samuraicircuits.com/MediaWiki/index.php?title=Ground_Control_Arcade_Box). 

This code has been tested on Arduino Leonardo and PRO Micro boards.

##TODO

- Speed hacks: responsivity is already really good, but it can be improved.

##Changelog

12/10/2013 - First release of Ground Control Arcade controller
03/23/2014 - Fixed USB HID descriptor for the Joystick (12 buttons, 2 axes)

