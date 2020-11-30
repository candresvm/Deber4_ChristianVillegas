
String recibe; 
String vector;
int tam; 
int i=0; 
String txs; 
int j=0; 
char dato;
const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (rs,en,d4,d5,d6,d7); 
void setup() {
  Wire.begin(4);
  Serial.begin(9600);
  lcd.begin(16,2);
  Wire.onReceive(receiveEvent);
}

void loop() {
  
         
}//end void loop

void receiveEvent(int bytes){
    while(Wire.available()){
          char dato=Wire.read();
             if(dato=='a'||dato=='e'||dato=='i'||dato=='o'||dato=='u')
             {
             for(i=0;i<1;i++){
              switch(dato){
                case 'a':
                    txs=txs+"@";
                break;
                case 'e':
                    txs=txs+"#";
                break;
                case 'i':
                    txs=txs+"!";
                break;
                case 'o':
                    txs=txs+"*";
                break;
                case 'u':
                    txs=txs+"$";
                break;
                }
              }
             }
             else
             {
              Serial.print(dato);
                lcd.setCursor(2,1);
                lcd.print(dato);
                delay(500);
             }
            Serial.print(txs);
            lcd.setCursor(2,1);
            lcd.print(txs);
            delay(500);
            txs="";         
    }
}
void requestEvent(){
  Wire.write("Hola");
}
