/**
 * Capacitive touch example, adapted by Eva Snyder from
 * http://www.instructables.com/id/Turn-a-pencil-drawing-into-a-capacitive-sensor-for/
 **/
#include <CapacitiveSensor.h>
// Pin for the LED
int RightEye = 4;
int LeftEye = 3;

// Pin to connect to your conductive sensor 
// (paperclip, conductive paint/fabric/thread, wire)
int capSensePin = 2;

// This is how high the sensor needs to read in order
//  to trigger a touch.  You'll find this number
//  by trial and error, or you could take readings at 
//  the start of the program to dynamically calculate this.
// If this is not sensitive enough, try a resistor with more ohms.
int touchedCutoff = 150;
CapacitiveSensor   cs_1_2 = CapacitiveSensor(0,2);        // 10M resistor between pins 0 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup(){
  // Serial.begin(9600);
  // Set up the LED
  pinMode(RightEye, OUTPUT);
  pinMode(LeftEye, OUTPUT);
  digitalWrite(RightEye, LOW);
  digitalWrite(LeftEye, LOW);
//  Serial.begin(9600);
  
  cs_1_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
}

void loop(){
  // If the capacitive sensor reads above a certain threshold,
  //  turn on the LED
  long start = millis();
  long sensorValue =  cs_1_2.capacitiveSensor(30);
//  Serial.println(sensorValue);
  if (sensorValue > touchedCutoff) {
    digitalWrite(RightEye,LOW);
  digitalWrite(LeftEye, HIGH);
  delay(750);
  digitalWrite(LeftEye, LOW);
  digitalWrite(RightEye,HIGH);
  delay(750);             // turn on the light for 5 seconds
  }
  
  else {
   digitalWrite(LeftEye, LOW);
  digitalWrite(RightEye,LOW);
  }
  
  delay(10); 
}
