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
