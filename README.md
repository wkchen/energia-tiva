energia-tiva
============

Some test programs for the Tiva C Launchpad using the Energia IDE

LED Test Program
----------------
 
  This program loops through the red, green and blue LEDs and turns
  each of them on for half a second.

  Note that RED_LED, GREEN_LED and BLUE_LED are defined in the Tiva
  header files, so we don't have to separately define them here

Serial Lib + LEDs
-----------------
  
  This program demonstrates the ability to parse commands that are sent over 
  the serial port, and perform actions based on them.  There following sample
  commands are implemented:
  
    "red" - turn on just red LED
    "green" - turn on just green LED
    "blue" - turn on just blue LED
    "white" - turn on all LEDs
    "off" - turn off all LEDs
  
  To issue the command, after loading the program, open the Serial Monitor from
  Energia.  Choose "Newline" instead of "No line ending" and then send commands.
  
  Once the program receives a newline, it will take the string in its buffer
  and run a command based on it.
  
  This program uses SerialEvent code from http://energia.nu/Tutorial_SerialEvent.html
