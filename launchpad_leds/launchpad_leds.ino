/*

  LED Test Program - Tiva Launchpad
  
  This program loops through the red, green and blue LEDs and turns
  each of them on for half a second.

  Note that RED_LED, GREEN_LED and BLUE_LED are defined in the Tiva
  header files, so we don't have to separately define them here
  
  Created 1/31/14
  by William Chen
  
  */

void setup()
{ 
  // Configure LED IO Pins
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop()
{
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(500);
  
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
  
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  delay(500);
}
