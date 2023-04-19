// const int trigPin = 7;
// const int echoPin = 6;
// // defines variables
// long duration;
// int distance;
// void setup() {
//   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
//   pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//   Serial.begin(9600); // Starts the serial communication
// }
// void loop() {
//   // Clears the trigPin
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   // Sets the trigPin on HIGH state for 10 micro seconds
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   // Reads the echoPin, returns the sound wave travel time in microseconds
//   duration = pulseIn(echoPin, HIGH);
//   // Calculating the distance
//   distance = duration * 0.034 / 2;
//   // Prints the distance on the Serial Monitor
//   Serial.print("Distance: ");
//   Serial.println(distance);
// }


#include <Keypad.h>
#include <string.h>
#include <ctype.h>
long randnum=0;
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {3, 4, 5, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 8, 9}; //connect to the column pinouts of the keypad
String temp;
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
String randstr="";
int bp=1;
void setup(){
  Serial.begin(9600);
  randomSeed(12);


  
    
    
}
int len=4;
int time=10;
void loop(){
  if(bp==1)
  {
    if(randnum==0)
    {
      randnum=random(1000,10000);
      Serial.println(randnum);
      temp=String(randnum);
    }
    
    verifyotp(temp,time);
  }
    
  
  // delay(5000);
  
  
  
}



void verifyotp(String temp,int time)
{
  char customKey = customKeypad.getKey();
            
      if(customKey!=NO_KEY)
      {  if(customKey=='#')
        {
            int size=randstr.length();
            randstr.remove(size-1);            
        }
        else
        {
          randstr+=customKey;
          if ((randstr)==(temp))
          {
            Serial.println("Same");
            randstr="";
          }
        }                
      }
                            
  // delay(7000);
}