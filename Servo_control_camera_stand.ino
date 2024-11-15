#include <Servo.h>
#define BTN_PIN 2
#define BTN_PIN2 3
#define BTN_PIN3 4
#define BTN_PIN4 5
#define MAX 180
#define MIN 0
#define MID 90

Servo myservo;  
Servo myservo2; 
int pos = 0;    
int pos2 = 0;    

void setup() {
  pinMode(BTN_PIN, INPUT);
  pinMode(BTN_PIN2, INPUT);
  pinMode(BTN_PIN3, INPUT);
  pinMode(BTN_PIN4, INPUT);
  myservo.attach(9); 
  myservo2.attach(10); 
  
  Serial.begin(9600);

  calibrateServo(myservo, myservo2);
}

void loop() {

  Serial.print(myservo.read());
  Serial.print(",\t");
  Serial.println(myservo2.read());

  if(digitalRead(BTN_PIN) && myservo.read() != 0){
    myservo.write(myservo.read()-1);
  }

  if(digitalRead(BTN_PIN2) && myservo.read() != 180){
    myservo.write(myservo.read()+1);
  }

  if(digitalRead(BTN_PIN3) && myservo2.read() != 0){
    myservo2.write(myservo2.read()-1);
  }

  if(digitalRead(BTN_PIN4) && myservo2.read() != 180){
    myservo2.write(myservo2.read()+1);
  }

  delay(15);
}

void calibrateServo(Servo myservo, Servo myservo2){
  for (pos = 0; pos <= MAX; pos++) { 
    myservo.write(pos);  
    myservo2.write(pos);                          
    delay(15);                       
  }
  for (pos = MAX; pos >= MID; pos--) { 
    myservo.write(pos);   
    myservo2.write(pos);               
    delay(15);                     
  }
}

void clockwise(){
  if(myservo.read() == 0) return;

  Serial.println("clockwise");
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);            
    delay(15);                     
  }
}

void counterclockwise(){
  if(myservo.read() == 180) return;
  
  Serial.println("counterclockwise");
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);             
    delay(15);                      
  }
}
