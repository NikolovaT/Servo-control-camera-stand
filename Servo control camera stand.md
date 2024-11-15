2024-08-07
https://www.aliexpress.com/item/1005004550155408.html

### Components: 

- Arduino board
- Servo x2
- Pushbuttons x4
- Capacitors 100$\mu F$  x2
- Resistor 10$k\Omega$ x4 
- Wires


### Connections:

| Servos GND (Brown)    | Capacitor cathode (-)                          |
| --------------------- | ---------------------------------------------- |
| Servos Vcc (Red)      | Capacitor anode (+)                            |
| Servos PWM (Orange)   | Pins 9 and 10                                  |
| Capacitor cathode (-) | Arduino GND                                    |
| Capacitor anode (+)   | Arduino 5V                                     |
| Pushbuttons           | Pins 2, 3, 4, 5                                |
| Pushbuttons           | Arduino 5V                                     |
| Pushbuttons           | GND through 10$k \Omega$ resistors (pull-down) |

### Code:

```
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
  calibrateServo(myservo, myservo2);

  Serial.begin(9600);
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
```

