#include <TimerOne.h>
//the pins of 4-digit 7-segment display attach to pin2-13 respectively 
int a = 7;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 2;
int g = 8;
int p = 9;
int d4 = 10;
int d3 = 11;
int d2 = 12;
int d1 = 13;
long n = 0;// n represents the value displayed on the LED display. For example, when n=0, 0000 is displayed. The maximum value is 9999. 
int x = 100;
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock
int count = 0;//Set count=0. Here count is a count value that increases by 1 every 0.1 second, which means 1 second is counted when the value is 10
int groundpin = A0; // write 0 to get ground
int redpin = A3; // select the pin for the green LED
int greenpin = A2; // select the pin for the red LED
int bluepin = A1; // select the pin for the blue LED
unsigned long millise = 0;
boolean Heated = false;
void setup()
{
  Serial.begin(9600);
  //set all the pins of the LED display as output
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);

  pinMode(1, INPUT_PULLUP);

  Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt(add); // attach the service routine here

  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(groundpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  tester = digitalRead(2)
}
/***************************************/ 
void loop()
{
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber((n/1000));// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber((n%1000)/100);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(n%100/10);//get the value of ten
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber(n%10);//Get the value of single digit
  delay(del);//delay 5ms
    
    
  millise = millis();
  if ( millise < 180000 ){
    digitalWrite (bluepin, HIGH);
    Serial.println("true");
    }
  if ( millise >= 180000 ){
    digitalWrite (bluepin, LOW);
    digitalWrite (redpin, HIGH);
    Serial.println("false");
    }
//  if (tester == LOW) {
//    digitalWrite (redpin, LOW);
//    digitalWrite (greenpin, HIGH);
  }
}
/**************************************/ 
void pickDigit(int x) //light up a 7-segment display
{
  //The 7-segment LED display is a common-cathode one. So also use digitalWrite to  set d1 as high and the LED will go out
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);

  switch(x)
  {
    case 0: 
    digitalWrite(d1, LOW);//Light d1 up 
    break;
    case 1: 
    digitalWrite(d2, LOW); //Light d2 up 
    break;
    case 2: 
    digitalWrite(d3, LOW); //Light d3 up 
    break;
    default: 
    digitalWrite(d4, LOW); //Light d4 up 
    break;
  }
}
//The function is to control the 7-segment LED display to display numbers. Here x is the number to be displayed. It is an integer from 0 to 9 
void pickNumber(int x)
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
    case 5: 
    five(); 
    break;
    case 6: 
    six(); 
    break;
    case 7: 
    seven(); 
    break;
    case 8: 
    eight(); 
    break;
    case 9: 
    nine(); 
    break;
  }
} 
void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}
void zero() //the 7-segment led display 0
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void one() //the 7-segment led display 1
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void two() //the 7-segment led display 2
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void three() //the 7-segment led display 3
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void four() //the 7-segment led display 4
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void five() //the 7-segment led display 5
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void six() //the 7-segment led display 6
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void nine() //the 7-segment led display 9
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
/*******************************************/
void add()
{
   // Toggle LED
  count ++;
  if(count == 10)
  {
    count = 0;
    n++;
    if(n == 180)
    {
      n = 13;
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      delay(500000);
      if(Heated == false)
      {
        Heated = true;
      }
    }
  }
}
