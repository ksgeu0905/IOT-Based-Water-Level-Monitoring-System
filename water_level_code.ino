// Arduino programming

#define trigpin 7
#define echopin 5
#define Relay_pin 6
int led1 = A0; //RED
int led3 = A4;//GREEN
int depth = 9; // in cm

void setup()
{
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(led1, OUTPUT);
  
  pinMode(led3, OUTPUT);
  pinMode(Relay_pin, OUTPUT);


  digitalWrite(led1,LOW);
  digitalWrite(led3, LOW);

  delay(1000);
}

void loop()
{
  int percen, duration, distance;
  digitalWrite(trigpin, HIGH);

  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);


  duration = pulseIn(echopin, HIGH);
  distance = ( duration / 2) / 29.1;

  if (  distance > 7   )
  {
    digitalWrite(led1, HIGH);
    //digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(Relay_pin, HIGH);
  }
  else if ( distance >2 && distance <= 4  )
  {
    digitalWrite(led1, LOW);
   // digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH); 
    digitalWrite(Relay_pin, HIGH);
     
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(Relay_pin, LOW);
  }
  
  
  }
 
