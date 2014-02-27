#Ground Control Arcade Box -- USB Controller

This code allows for the usage of an Arduino Leonardo as a USB joystick.
It was contributed by Kevin Peat and modified for the Ground Control arcade project.

In order to use this code, you have to install modified version of the USBAPI.h and HID.cpp files. [Follow this link for instructions](http://www.imaginaryindustries.com/blog/?p=80).

For instructions on how to wire the Ground Control joystick, [follow this wiki page](http://www.samuraicircuits.com/MediaWiki/index.php?title=Ground_Control_Arcade_Box). 

This code has been tested on Arduino Leonardo and the PRO Micro boards.

##TODO

- Fix HID descriptor for the arcade controller;
- Speed hacks: responsivity is already really good, but it can be improved.
