//# LJ18A3-3-Z-BX-Proximity-Switch
//Proximity Switch  LJ18A3-3-ZBX - can be used with LJ12A3-4-ZBX

//Tested with Arduino UNO

//Connect Arduino to a PROXIMITY SWITCH
// Proximity switch used: LJ18A3-3-ZBX - this is NORMALLY CLOSE (the switch and its LED stays ON ALL THE TIME, and will remain in CLOSED //CIRCUIT, until the proximity switch detects aluminum/metal material, than it OPENS the circuit!)
// Also, I've included the SERIAL.PRINT - output to the serial port - use CTRL+SHIFT+M to open the com port window
// Most of the code and wiring was inspired from youtube by Dorian
// Thanks to Dorian McIntire! Here is his video : https://www.youtube.com/watch?v=soJ4czkKpT4
// Tony Fleming testing  LJ18A3-3-ZBX, Inductive Proximity Switch  V1.0  10-15-2016

//Make your COM1 -or whatever your COM port number is- as small as you can horizontally - mine is 15 lines tall and 55 characters wide
//Set your COM port to 230400 baud rate
//This will make it look like the COM port window is cleared before the next value is printed
//ALSO make sure your AUTO SCROLL is UN-checked and the NO LINE ENDING is selected!
//There is no way to clear the COM port window, so this just emulates the "output window"!



int sensorVal;

void setup() {

  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);

  // initialize serial communications at 9600 bps:
  Serial.begin(230400);

  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  sensorVal = digitalRead(2);
  if (sensorVal == HIGH) {
    digitalWrite(11, HIGH); digitalWrite(12, LOW); tone(13, 1000);

    for (int i = 0; i <= 12; i++)
      Serial.println();

    Serial.print("SENSOR HAS DETECTED A METAL and/or ALUMINUM : ");
    Serial.println("  YES ");
    Serial.println("--------------------------------------------------- ");
    Serial.print("SENSORS VALUE IS                            :   ");
    Serial.println (sensorVal);
    Serial.println("--------------------------------------------------- ");
    delay (500);

  }
  else {
    digitalWrite(11, LOW); digitalWrite(12, HIGH); noTone(13);
delay (1000);
   { for (int i = 0; i <= 6; i++)
      Serial.println();

    Serial.print("SENSOR HAS DETECTED A METAL and/or ALUMINUM : ");
    Serial.println("  NO ");
    Serial.println("--------------------------------------------------- ");
    Serial.print("SENSORS VALUE IS                            :   ");
    Serial.println (sensorVal);
    Serial.println("--------------------------------------------------- ");

    for (int i = 0; i <= 4; i++)
      Serial.println();}

  }
}
