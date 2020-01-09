#include <Servo.h> //using the servo library
// constants won't change. They're used here to
// set pin numbers:
Servo myservo;
const int buttonPin = 8;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
const int TrigPin = 3;//Trig attach to pin2
const int EchoPin = 4;//Echo attach to pin3
int pos = 0;
int on = 0; 
int potient = A0;
int potientValue = 0;
float cm; // fjöldi cm sem mældir eru
int led1 = 5;
int takki = 8;
//t skynjari = A0;
int takkiValue;
//t skynjariValue;
int takkiCount = 0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH && on == 0 ) {
    on = 1;
   potientValue = analogRead(potient);
  potientValue = map(potientValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(potientValue);                  // sets the servo position according to the scaled value 
  delay(15);//give the servomotor time to go to position
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
 
  cm = pulseIn(EchoPin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  Serial.println(cm);
  if(cm < 20){
    
    digitalWrite(led1, HIGH);

  }
  else {
    digitalWrite(led1, LOW);
  }
  Serial.println(cm);


} else if(buttonState == HIGH && on == 1){
  

    
    
    
on = 0;
    // turn LED off:
   // digitalWrite(ledPin, LOW);
  }
}
