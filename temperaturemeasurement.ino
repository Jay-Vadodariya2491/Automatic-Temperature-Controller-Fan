#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int tempPin = A0; 
int fan = 11; 
int led = 8; 
float temp;
int tempMin = 10; 
int tempMax = 60; 
int fanSpeed;
int fanLCD;
float a;

void setup() {
pinMode(fan, OUTPUT);
pinMode(led, OUTPUT);
pinMode(tempPin, INPUT);
lcd.begin(16,2);
Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  a=analogRead(A0);
temp=(a*(5.0/1024.0)*100)/1.54;
Serial.println(temp);

if(temp<tempMin) 
{
fanSpeed = 0;
analogWrite(fan, fanSpeed);
fanLCD=0;
digitalWrite(fan, LOW);
}

if((temp >= tempMin) && (temp <= tempMax)) 
{
fanSpeed = 255;

fanLCD = map(temp, tempMin, tempMax, 0, 100); 
analogWrite(fan, fanSpeed); 
}
 
if(temp > tempMax)
{
digitalWrite(led, HIGH); 
}
else 
{
digitalWrite(led, LOW);
}
 
lcd.print("TEMP: ");
lcd.print(temp); 
lcd.print("C ");
lcd.setCursor(0,1);
lcd.print("FANS: ");
lcd.print(fanLCD); 
lcd.print("%");
delay(200);
lcd.clear();
}