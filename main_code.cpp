// C++ Code
// WALKING LED ARDUINO

const int btnPin = 8;
const int led1Pin = 7;
const int led2Pin = 6;
const int led3Pin = 5;
const int led4Pin = 4;
const int led5Pin = 3;
const int led6Pin = 2;

int ranNum;
int ranDel;
int i;

enum fcnMode {
  OFF,
  LED1,
  LED2,
  LED3,
  LED4,
  LED5,
  LED6,
  ALL,
  NBSTATE
    
}; // OFF = 0 and NBSTATE=7

int ledState1 = LOW, 
    ledState2 = LOW, 
    ledState3 = LOW,
    ledstate4 = LOW,
    ledstate5 = LOW,
    ledstate6 = LOW;           // ledState used to set the LED
unsigned long buttonState = 0;
int funcState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // initialize serial port
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT); 
  pinMode(led4Pin, OUTPUT); 
  pinMode(led5Pin, OUTPUT); 
  pinMode(led6Pin, OUTPUT); 
}

// loop function
void loop() {
  buttonPressed();
  setMode();
}
  
void buttonPressed() {
  buttonState = pulseIn(btnPin, HIGH, 1000000);
  if (buttonState > 50) {
      funcState += 1;
      Serial.print("Button state n: ");
      Serial.println(funcState);
  }
  funcState = funcState % NBSTATE;
}
  
void setMode() {
  // All Off
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);
  digitalWrite(led5Pin, LOW);
  digitalWrite(led6Pin, LOW);

  Serial.print("Function : ");
  Serial.println(funcState);

  switch (funcState) {
    case OFF:
        break;
    case LED1:
        for(int pin = 6; pin >= 2; pin--)
        {
        digitalWrite(pin, HIGH);
        delay(200);
        digitalWrite(pin+1, LOW);
        delay(200);
        }
        for(int pin = 6; pin >= 2; pin--)
        {
        digitalWrite(pin+1, HIGH);
        delay(200);
        digitalWrite(pin+2, LOW);
        delay(200);
        }
        for(int pin = 6; pin >= 2; pin--)
        {
        digitalWrite(pin+2, HIGH);
        delay(200);
        digitalWrite(pin+3, LOW);
        delay(200);
        }
        for(int pin = 6; pin >= 2; pin--)
        {
        digitalWrite(pin+3, HIGH);
        delay(200);
        digitalWrite(pin+4, LOW);
        delay(200);
        }
        for(int pin = 6; pin >= 2; pin--)
        {
        digitalWrite(pin+4, HIGH);
        delay(200);
        digitalWrite(pin+5, LOW);
        delay(200);
        }
        for(int pin = 7; pin >= 2; pin--)
        {
        digitalWrite(pin+5, HIGH);
        delay(200);
        }
        for(int pin = 6; pin >= 2; pin--)
        {
        digitalWrite(pin, LOW);
        delay(200);
        }
        break;
    case LED2:
        for(int i=2; i<=7; i++){
        digitalWrite(i, HIGH);
        delay(200);
        }
        for(int i=2; i<=7; i++){
        digitalWrite(i, LOW);
        delay(200);
        }
        for(int i = 7; i>=2; i--){
        digitalWrite(i, HIGH);
        delay(200);
        }
        for(int i = 7; i>=2; i--){
        digitalWrite(i, LOW);
        delay(200);
        }
        break;
    case LED3:
        for (i = 2; i <= 7 ; i++) {
        digitalWrite(i, HIGH);
        delay(200);
        digitalWrite(i, LOW);
        delay(200);
        }
        for (i = 7; i >= 2 ; i--) {
        digitalWrite(i, HIGH);
        delay(200);
        digitalWrite(i, LOW);
        delay(200);
        }
        break;
    case LED4:
        for(int i=2; i<7; i++){
        digitalWrite(i, HIGH);
        delay(200);
        digitalWrite(i+1, HIGH);
        delay(200);
        digitalWrite(i+2, HIGH);
        delay(200);
        digitalWrite(i, LOW);
        delay(200);
        digitalWrite(i+1, LOW);
        delay(200);
        }
        for(int i=7; i>2; i--){
        digitalWrite(i, HIGH);
        delay(200);
        digitalWrite(i-1, HIGH);
        delay(200);
        digitalWrite(i-2, HIGH);
        delay(200);
        digitalWrite(i, LOW);
        delay(200);
        digitalWrite(i-1, LOW);
        delay(200);
        }
        break;
    case LED5:
        for (i = 2; i <= 7 ; i++) {
        digitalWrite(i, HIGH);
        delay(500);
        }
        for (i = 7; i >= 2 ; i--) {
        digitalWrite(i, LOW);
        delay(500);
        }
        break;
    case LED6:
        ranNum=random(2,7);
        ranDel=random(1000,1000);
        digitalWrite(ranNum, HIGH);
        delay(ranDel);
        digitalWrite(ranNum, LOW);
        break;
    case ALL:
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2Pin, HIGH);
        digitalWrite(led3Pin, HIGH);
        digitalWrite(led4Pin, HIGH);
        digitalWrite(led5Pin, HIGH);
        digitalWrite(led6Pin, HIGH);
        break;
    }
}
