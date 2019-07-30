//sleep
#include <avr/sleep.h>


//send
int IRledPin =  3;
#define LED 13
#define POWER 8
#define CHPLUS 9
#define CHMINUS 10
#define VOLPLUS 11
#define VOLMINUS 12

//receive
#define IRpin_PIN      PIND
#define IRpin          2
 
// the maximum pulse we'll listen for - 65 milliseconds is a long time
#define MAXPULSE 65000
 
// what our timing resolution should be, larger is better
// as its more 'precise' - but too large and you wont get
// accurate timing
#define RESOLUTION 20 
 
// we will store up to 100 pulse pairs (this is -a lot-)
uint16_t pulses[100][2];  // pair is high and low pulse 
uint8_t currentpulse = 0; // index for pulses we're storing
int count=0; 
void setup()
{
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  
  pinMode(IRledPin, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(POWER,INPUT_PULLUP) ;    //スイッチに接続ピンをデジタル入力に設定
  pinMode(CHPLUS,INPUT_PULLUP) ;    //スイッチに接続ピンをデジタル入力に設定
  pinMode(CHMINUS,INPUT_PULLUP) ;    //スイッチに接続ピンをデジタル入力に設定
  pinMode(VOLPLUS,INPUT_PULLUP) ;    //スイッチに接続ピンをデジタル入力に設定
  pinMode(VOLMINUS,INPUT_PULLUP) ;    //スイッチに接続ピンをデジタル入力に設定
  Serial.begin(9600);
  //Serial.println("Ready to send IR!");
}
void loop()
{
int  a=0;
digitalWrite(LED,HIGH);

 if(digitalRead(POWER)==LOW){
    a=1;
    count=0;
  }
  else if(digitalRead(CHPLUS)==LOW){
    a=3;
    count=0;
  }
  else if(digitalRead(CHMINUS)==LOW){
    a=4;
    count=0;
  }
  else if(digitalRead(VOLPLUS)==LOW){
    a=5;
    count=0;
  }
  else if(digitalRead(VOLMINUS)==LOW){
    a=6;
    count=0;
  }
  else{
    count++;
    Serial.println(count);
    //do nothing
  }


if(count==2000){
  //Serial.println("sleep mode");
  //Serial.println(count);
  digitalWrite(LED,LOW);
  count=0;
  sleep_mode();
}
else{
  //do nothing
}
     
  switch(a)
  {
     
    case 1: power();    //if it receives the number "1" from the app then the case one will be executed
            /*digitalWrite(LED,HIGH);
            delay(500);
            digitalWrite(LED,LOW);*/
             
             
            break;
    case 2:tvpower();
             
            break;
    case 3:chplus();
            /*digitalWrite(LED,HIGH);
            delay(500);
            digitalWrite(LED,LOW);*/
           break;
    case 4:chminus();
           /* digitalWrite(LED,HIGH);
            delay(500);
            digitalWrite(LED,LOW);*/
           break;
    case 5:volplus();
           /* digitalWrite(LED,HIGH);
            delay(500);
            digitalWrite(LED,LOW);*/
           break;
    case 6:volminus();
           /* digitalWrite(LED,HIGH);
            delay(500);
            digitalWrite(LED,LOW);*/
            
           break;
                             //all the data provided corresponds to my tv remote thus you have to modify to your needs
    case 10:  zero();        //if it receives the number "10" from the app then the case 10 will be executed thus the respective channel is switched
              delay(700);
              nine();
              delay(700);
              one();
              delay(700);
              zero();
              delay(700);
              break;          //channel number 910 will be switched
     
  }  
}

void pulseIR(long microsecs)
{
  cli();
  while (microsecs > 0)
  {
    digitalWrite(IRledPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(IRledPin, LOW);
    delayMicroseconds(10);
    microsecs -= 26;
  }
  sei();
}

void power()   /*the function stores the data for the power button taken from the step-1*/
{
//delayMicroseconds(37168); pulseIR(3640);
//delayMicroseconds(1580); pulseIR(580);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1180); pulseIR(540);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1180); pulseIR(540);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(540);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(6904); pulseIR(3620);
delayMicroseconds(1600); pulseIR(560);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1160); pulseIR(560);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1180); pulseIR(540);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(500);
delayMicroseconds(360); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);

  
  //the data is for my remote so update the data with yours

}
void tvpower()
{

}
void chplus()
{
//delayMicroseconds(244); pulseIR(3640);
//delayMicroseconds(1580); pulseIR(580);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1160); pulseIR(560);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1160); pulseIR(560);
//delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(8644); pulseIR(3640);
delayMicroseconds(1580); pulseIR(580);
delayMicroseconds(300); pulseIR(560);
delayMicroseconds(1180); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1180); pulseIR(540);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(520);
delayMicroseconds(340); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);

//put the data of your channel plus button in this section
}

void chminus()
{
//delayMicroseconds(59316); pulseIR(3640);
//delayMicroseconds(1580); pulseIR(580);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1160); pulseIR(560);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1180); pulseIR(540);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1200); pulseIR(520);
//delayMicroseconds(340); pulseIR(520);
//delayMicroseconds(1200); pulseIR(520);
//delayMicroseconds(340); pulseIR(520);
//delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(480);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(8644); pulseIR(3640);
delayMicroseconds(1600); pulseIR(560);
delayMicroseconds(300); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1180); pulseIR(560);
delayMicroseconds(320); pulseIR(520);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(340); pulseIR(500);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);


}
void volplus()
{
//delayMicroseconds(840); pulseIR(3620);
//delayMicroseconds(1600); pulseIR(580);
//delayMicroseconds(300); pulseIR(560);
//delayMicroseconds(1160); pulseIR(540);
//delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(6884); pulseIR(3640);
delayMicroseconds(1620); pulseIR(560);
delayMicroseconds(300); pulseIR(540);
delayMicroseconds(1180); pulseIR(540);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1180); pulseIR(540);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);

}
void volminus()
{
//delayMicroseconds(29356); pulseIR(3640);
//delayMicroseconds(1580); pulseIR(580);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1180); pulseIR(540);
//delayMicroseconds(320); pulseIR(520);
//delayMicroseconds(1200); pulseIR(540);
//delayMicroseconds(320); pulseIR(540);
//delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(6884); pulseIR(3640);
delayMicroseconds(1600); pulseIR(560);
delayMicroseconds(320); pulseIR(520);
delayMicroseconds(1200); pulseIR(540);
delayMicroseconds(320); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(540);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(360); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);

  
}
void zero()
{
  
}
void one()
{
  
}
void two()
{
  
}
void three()
{
}
void nine()
{
  
}
//add for all the 10 numbers.

//similarly you can add any no of functions for each buttons
