// Author : Chakri.M
// Project : Pupil+ Bluetooth version
// Date : 18-07-16
// This code works only for Arduino Micro + Bluetooth module(HC-05)
#define WLU 9
#define WLD 10
#define WRU 11
#define WRD 13
#define ON_TIME 3000
#define OFF_TIME 500
#define DELAY 500
int counter=10;
int intensity = 100;
void setup() {
  pinMode(WLU,OUTPUT);
  pinMode(WLD,OUTPUT);
  pinMode(WRU,OUTPUT);
  pinMode(WRD,OUTPUT);
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
if(Serial.available() or Serial1.available()){ // Serial classes are different in Arduino Micro development board. As it uses two different serial ports for bluetooth and usb.
 char IN=Serial1.read();
 Serial.println(IN); 
 if(IN=='x'){
  counter=0;
  delay(3000); // initialization
  }
 if(IN=='z'){
  counter=10;
  }
  }
if(counter<9){
  if(counter%2==0){
      analogWrite(WRU, intensity);
      analogWrite(WRD, intensity);
      delay(ON_TIME);
      turnThemOff();
      delay(OFF_TIME);
      }
  else if(counter%2!=0){
      analogWrite(WLU, intensity);
      analogWrite(WLD, intensity);
      delay(ON_TIME);      
      turnThemOff();
      delay(3000);
      }   
   counter++;
  }
else{
  turnThemOff();
  }
}



void turnThemOff() {
  analogWrite(WLU, 0);
  analogWrite(WLD, 0);
  analogWrite(WRU, 0);
  analogWrite(WRD, 0);
}
