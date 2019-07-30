#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int LED = 2;
void setup() {
     Serial.begin(9600) ;      // パソコン(ArduinoIDE)とシリアル通信の準備を行う
     pinMode(LED,OUTPUT);
}
void loop() {
     int sens ;

     sens = analogRead(0) ;              // アナログ０番ピンからセンサー値を読込む

     Serial.println(sens) ;             // 値をパソコン(ＩＤＥ)に送る
  

     if(sens>0){
      lcd.begin();
      lcd.backlight();
      lcd.print("Hello, world!");
      digitalWrite(LED,HIGH);
     }
     else{
      lcd.clear();
      digitalWrite(LED,LOW);
     }
       delay(100) ;                      // １秒毎に繰り返す

}
