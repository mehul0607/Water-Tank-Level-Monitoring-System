#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
long duration;
long distance;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  Serial.begin(9600);
  

  lcd.begin();
  lcd.backlight();
  pinMode(7,INPUT);   // echo
  pinMode(8,OUTPUT);  // trig
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(8,LOW);
  delayMicroseconds(2);
  digitalWrite(8,HIGH);
  delayMicroseconds(10);
  digitalWrite(8,LOW);

  duration = pulseIn(7,HIGH);

  distance = duration/58.2;

  

  Serial.println(distance);

  delay(50);

  if(distance <= 20)
  {
       digitalWrite(13, HIGH);
       digitalWrite(12, LOW);
       digitalWrite(11, LOW); 
       lcd.setCursor(0,0);
       lcd.print("Level is HIGH");
       lcd.setCursor(0,1);
       lcd.print("Motor is OFF....");
   
   delay(400);
            
  }
  if(distance > 20 && distance < 70)
  {
       digitalWrite(12, HIGH);
       digitalWrite(13, LOW);
       digitalWrite(11, LOW);  
       
       lcd.setCursor(0,0);
       lcd.print("Level is Med.");
       lcd.setCursor(0,1);
       lcd.print("Motor is working");
       delay(400);
        
  }
  if(distance >= 70)
  {
       digitalWrite(11, HIGH);
       digitalWrite(12, LOW);
       digitalWrite(13, LOW); 
       lcd.setCursor(0,0);

       lcd.print("Level is LOW.");
       lcd.setCursor(0,1);
       lcd.print("Motor is ON.....");
       
       delay(400);
      
    
  }
  if(distance <=10)
  {
    digitalWrite(5, HIGH); 
    //delay(50);
  }
 
  
   
}
