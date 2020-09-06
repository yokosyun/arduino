//send
int IRledPin =  3;
#define LED 10

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
 
void setup()
{
  pinMode(IRledPin, OUTPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready to send IR!");
}
void loop()
{
char  a=0;
  if(Serial.available()>0)
  {
   
    a=Serial.read();
    //1=49
    //ASCII【American Standard Code for Information Interchange】表記だから
    
     Serial.print(a);
  a=a-48;
     
  switch(a)
  {
     
    case 1: power();    //if it receives the number "1" from the app then the case one will be executed
            digitalWrite(LED,HIGH);
             delay(1000);
             digitalWrite(LED,LOW);
             delay(1000);
             
            break;
    case 2:tvpower();
             
            break;
    case 3:chplus();
            
           break;
    case 4:chminus();
           break;
    case 5:volplus();
           break;
    case 6:volminus();
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
/* 
delayMicroseconds(25308); pulseIR(3580);
delayMicroseconds(1640); pulseIR(540);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1180); pulseIR(560);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1180); pulseIR(560);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1180); pulseIR(540);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1220); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(520);
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
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(480);
delayMicroseconds(380); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(6884); pulseIR(3600);
delayMicroseconds(1620); pulseIR(600);
delayMicroseconds(300); pulseIR(560);
delayMicroseconds(1160); pulseIR(540);
delayMicroseconds(320); pulseIR(520);
delayMicroseconds(1200); pulseIR(540);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
delayMicroseconds(1200); pulseIR(540);
delayMicroseconds(320); pulseIR(540);
delayMicroseconds(1200); pulseIR(520);
delayMicroseconds(340); pulseIR(520);
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
delayMicroseconds(1240); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(360); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
delayMicroseconds(1240); pulseIR(500);
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
delayMicroseconds(400); pulseIR(460);
delayMicroseconds(1220); pulseIR(500);
delayMicroseconds(1240); pulseIR(480);
*/

}
void tvpower()
{

}
void chplus()
{
//put the data of your channel plus button in this section
}

void chminus()
{

}
void volplus()
{
  
}
void volminus()
{
  
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
