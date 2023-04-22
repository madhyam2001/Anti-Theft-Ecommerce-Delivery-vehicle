
#include <Keypad.h>
#include <string.h>
#include <ctype.h>
#include <LiquidCrystal.h>

char customKey;
LiquidCrystal lcd(30, 32, 22, 24, 26, 28);
long randnum=0;
// int Lock = 32; // Connecting the relay to the 5th pin
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
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
String randstr="";
char inputString[16];
int stringIndex = 0;
int bp=1;
void setup(){
  randomSeed(12);
  lcd.begin(16, 2);
  // pinMode(Lock, OUTPUT);
  // digitalWrite(Lock, HIGH);
  
    
    
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
    
    verifyotp(temp);
  }
  
  
  
}
  
  
  




void verifyotp(String temp)
{
  customKey = customKeypad.getKey();
            
      if(customKey!=NO_KEY)
      {  if(customKey=='#')
        {
            int size=randstr.length();
            randstr.remove(size-1);
             if (stringIndex > 0) {
              stringIndex--;
              inputString[stringIndex] = '\0'; // Null-terminate string
              lcd.setCursor(stringIndex, 0);
              lcd.print(" "); // Clear LCD at current position
              lcd.setCursor(stringIndex, 0);
      }            
        }
        else
        {
          // lcd.print(customKey);
          if (stringIndex < 15) {
          inputString[stringIndex] = customKey;
          stringIndex++;
          inputString[stringIndex] = '\0'; // Null-terminate string
          lcd.print(customKey);
      }  
          randstr+=customKey;
          if ((randstr)==(temp))
          {
            lcd.clear();
            lcd.print("Lock Opened");
            Serial.println("Same");
            // digitalWrite(Lock, LOW);
            randstr="";
          }
        }                
      }
                            
  // delay(7000);
}