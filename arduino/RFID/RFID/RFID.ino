#include <SPI.h>
#include <MFRC522.h>
#include <string.h>
#include <stdio.h>
#define LED  2
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

//隙間を空けると間違いになる
#define UID1 "8635E825"  // DumpInfo.inoで読み取ったUIDを記入
#define UID2 "97493726"  // DumpInfo.inoで読み取ったUIDを記入
#define UID3 "xx xx xx xx xx xx xx"  // DumpInfo.inoで読み取ったUIDを記入
#define UID4 "xx xx xx xx xx xx xx"  // DumpInfo.inoで読み取ったUIDを記入
#define UID5 "xx xx xx xx xx xx xx"  // DumpInfo.inoで読み取ったUIDを記入
#define UID6 "xx xx xx xx xx xx xx"  // DumpInfo.inoで読み取ったUIDを記入
#define UID7 "xx xx xx xx xx xx xx"  // DumpInfo.inoで読み取ったUIDを記入
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

MFRC522::MIFARE_Key key;

#include<Servo.h>
Servo servo1; //任意のサーボモータークラスを用意

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  //dump_byte_array(key.keyByte, MFRC522::MF_KEY_SIZE);
  pinMode(LED,OUTPUT);
  servo1.attach(3);
 
}

void loop() {
   String strUID;
    if (mfrc522.PICC_IsNewCardPresent()==1) {
    Serial.println("passed");
    delay(100);
  }
  else{
    Serial.println("returned");
    delay(100);
    return;
  }



  if(mfrc522.PICC_ReadCardSerial()==1){
      Serial.println("can read");
      delay(100);
  }

else {
    Serial.println("returned");
    delay(100);
    return;
  }
  delay(1000);

//buffferサイズの読み取りと、UIDの読みこみ
    String strBuf[mfrc522.uid.size];
    Serial.println("mfrc522.uid.size");
    Serial.println(mfrc522.uid.size);
    for (byte i = 0; i < mfrc522.uid.size; i++) {
  
      strBuf[i]=String(mfrc522.uid.uidByte[i], HEX);// (E)using a constant integer
      
      if(strBuf[i].length() == 1){  // 1桁の場合は先頭に0を追加
        strBuf[i] = "0" + strBuf[i];

      }
      Serial.println("strBuf[i]:");
      Serial.println(strBuf[i]);
      delay(100);
      strUID += strBuf[i];
    }
   delay(100);
   //String strUID = strBuf[0] +" "+ strBuf[1] + " " + strBuf[2] + " " + strBuf[3];
   Serial.println("strUID:");
   Serial.println(strUID);
    delay(500);
    Serial.println("result:");
    if ( strUID.equalsIgnoreCase(UID1) ){  // 大文字小文字関係なく比較
      servo1.write(90);
      Serial.println("recognized:1");
      delay(2000);
      servo1.write(0);
    }
    else if ( strUID.equalsIgnoreCase(UID2) ){
      Serial.println("recognized:2");
    }
    else if ( strUID.equalsIgnoreCase(UID3) ){
      Serial.println("3");
    }
    else if ( strUID.equalsIgnoreCase(UID4) ){
      Serial.println("4");
    }
    else if ( strUID.equalsIgnoreCase(UID5) ){
      Serial.println("5");
    }
    else if ( strUID.equalsIgnoreCase(UID6) ){
      Serial.println("6");
    }
    else if (strUID.equalsIgnoreCase(UID7) ){
      Serial.println("7");
    }
    else{
      Serial.println("nothing");
    }

}


/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX); 
       //読み取ったデータサイズとＵＩＤを表示
    }
}
