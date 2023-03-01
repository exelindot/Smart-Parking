// Pin HCSR_04
#define trigPin 16    //D0
#define echoPin 5    //D1
#define trigPin_1 14  //D5
#define echoPin_1 12  //D6
#define trigPin_2 13  //D7
#define echoPin_2 15  //D8

long duration;
float d;
long duration_1;
float e;
long duration_2;
float k;

//Pin IR Sensor IR
int in = 4;  //D2
int isObstacle = HIGH;
//Servo
Servo myservo;


void deklarasi() {
  //WIFI
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);
  // digitalWrite(trigPin, LOW);
  // digitalWrite(trigPin_1, LOW);
  // digitalWrite(trigPin_2, LOW);
  //Servo
  myservo.attach(2);  //D4

  //IR sensor
  pinMode(in, INPUT);
}

void palang() {
  isObstacle = digitalRead(in);     // // Read IR sensor output
  Serial.println(digitalRead(in));  // // print the output
  // // isObstacle ==low there is obstacle infront of sensor
  // // using serial monitor we can see this output
  if (isObstacle == LOW) {
    myservo.write(0);
    Serial.println("buka");
  } else {
    myservo.write(180);
    Serial.println("tutup");
  }
}