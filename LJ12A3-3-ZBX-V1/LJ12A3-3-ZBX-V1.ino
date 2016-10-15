//Published on Dec 18, 2014
//A video to show how to interface a sinking proximity sensor to an Arduino. When the sensor is activated a green LED lights up 
//and a tone is generated from a speaker. When the sensor is inactivated a red LED lights up.
// Downloaded from: https://www.youtube.com/watch?v=soJ4czkKpT4
// Tony testing  LJ12A3-4/ZBX Inductive Proximity Switch  V1.0  10-13-2016


  
int sensorVal;

void setup(){
  
//configure pin2 as an input and enable the internal pull-up resistor
pinMode(2, INPUT_PULLUP);

// initialize serial communications at 9600 bps:
  Serial.begin(9600);

pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() {
  sensorVal = digitalRead(2);
  if (sensorVal == HIGH) {
    digitalWrite(11, LOW); digitalWrite(12, HIGH); noTone(13);
  }
  else {
    digitalWrite(11, HIGH); digitalWrite(12, LOW); tone(13, 1000);
  
  Serial.print("sensor detected metal :");
  Serial.println("YES ");
  Serial.println("-------------------- ");
  Serial.print("sensors value is: ");
  Serial.println (sensorVal);
  Serial.println("-------------------- ");
  delay (500);
  
}
}
