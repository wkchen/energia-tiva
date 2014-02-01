/*

  LED Test Program - Serial Lib
  
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
  
  Created 1/31/14
  by William Chen
  
  */
  
String inputString;
boolean stringComplete = false;
  
void setup()
{
  // put your setup code here, to run once:
  // Configure LED IO Pins
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  Serial.begin(9600);
  inputString.reserve(200);
}

void loop()
{

  
  if(stringComplete)
  {
    inputString.trim();   // Make sure we remove extra whitespace & newlines
    Serial.println("Got: " + inputString);
    parseStringLED(inputString);
    inputString = "";
    stringComplete = false;
  }
}

void parseStringLED(String s)
{
  s.trim();
  
  if (s == "red")
  {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  } 
  else if (s == "green") 
  {
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    
  } 
  else if (s == "blue") 
  {
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
  else if (s == "off")
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
  else if (s == "white")
  {
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
  } 
  else
  {
    Serial.println("Not supported");
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX. This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

