//geekmatic.in.ua

int motorPin1 = 8; // Blue / Синий   - 28BYJ48 pin 1
int motorPin2 = 9; // Pink  / Розовый  - 28BYJ48 pin 2
int motorPin3 = 10; // Yellow / Желтый - 28BYJ48 pin 3
int motorPin4 = 11; // Orange  / Оранжевый - 28BYJ48 pin 4

int motorPin5 = 2; // Blue / Синий   - 28BYJ48 pin 1
int motorPin6 = 3; // Pink  / Розовый  - 28BYJ48 pin 2
int motorPin7 = 4; // Yellow / Желтый - 28BYJ48 pin 3
int motorPin8 = 5; // Orange  / Оранжевый - 28BYJ48 pin 4  

int motorSpeed = 0;        
//полушаговый режим
int lookup[8] = {B01001, B00001, B00011, B00010, B00110, B00100, B01100, B01000};
//полношаговый режим
int lookup1[8] = {B01001, B01100, B00110, B00011, B01001, B01100, B00110, B00011};

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);
}

void loop(){
  int VariableResistor = analogRead(A7);
  motorSpeed = map(VariableResistor, 0, 1023, 2000, 500); 

  //anticlockwise();
  clockwise();
}

// функция вращает мотор против часовой стрелки
void anticlockwise()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

// функция вращает мотор по часовой стрелке
void clockwise()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out)
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
  digitalWrite(motorPin5, bitRead(lookup1[out], 0));
  digitalWrite(motorPin6, bitRead(lookup1[out], 1));
  digitalWrite(motorPin7, bitRead(lookup1[out], 2));
  digitalWrite(motorPin8, bitRead(lookup1[out], 3));
}
