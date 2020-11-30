
#include <Wire.h>  
char dato;  
const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
#include <LiquidCrystal.h>
LiquidCrystal lcd (rs,en,d4,d5,d6,d7);
void setup() {
  Wire.begin(); 
  Serial.begin(9600); 
  

}

void loop() {
   if(Serial.available()>0){ 
    dato=Serial.read(); 
    Wire.beginTransmission(4);
    Wire.write(dato); 
    Wire.endTransmission(); 
  }
  delay(1000);
  Wire.requestFrom(4,4); 
  while(Wire.available()){ 
    Serial.println("Mensaje  recivida:"); 
    char c=Wire.read(); 
    lcd.setCursor(2,1);
    lcd.print(c);
    }
  
}
