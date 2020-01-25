// these constants describe the pins. They won't change:
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
int pressureAnalogPin = 0; //pin where our pressure pad is located.
int pressureReading; //variable for storing our reading

//Adjust these if required.
int noPressure = 5; //max value for no pressure on the pad
int lightPressure = 100; //max value for light pressure on the pad
int mediumPressure = 200; //max value for medium pressure on the pad

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode (8, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}

void loop() {
  
  // print the sensor values:
  //Serial.print(analogRead(xpin));
  // print a tab between values:
  //Serial.print("\t");
  //Serial.print(analogRead(ypin)*100);
  // print a tab between values:
  //Serial.print("\t");
  //Serial.print(analogRead(zpin));
  //Serial.println();
  // delay before next reading:
  //delay(100);
   pressureReading = analogRead(pressureAnalogPin);
  
  Serial.print("Pressure Pad Reading = ");
  Serial.println(pressureReading);
  delay (100);

  if (pressureReading < noPressure) {
    Serial.println(" - No pressure");
    digitalWrite(8,LOW);
  } else if (pressureReading < lightPressure) {
    Serial.println(" - Light Pressure");
    digitalWrite(8,LOW);
  } else if (pressureReading < mediumPressure) {
    Serial.println(" - Medium Pressure");
    digitalWrite(8,LOW);
  } else{
    Serial.println(" - High Pressure");
    digitalWrite(8,HIGH);
  }
  Serial.print("Accelerometer Reading = ");
  Serial.println(analogRead(ypin));
  
  if (analogRead(ypin)>263)
  {
    digitalWrite(13,HIGH);
  }
  if (analogRead(ypin)<260)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }

}
