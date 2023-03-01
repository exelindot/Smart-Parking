
void sensors() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  d = duration * 0.034 / 2;

  Serial.println("Distance = ");
  Serial.println(d);
  Serial.println("cm");

  // kedua
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration_1 = pulseIn(echoPin_1, HIGH);
  // Calculate the distance:
  e = duration_1 * 0.034 / 2;
  Serial.print(" ");
  Serial.println("Distance_1 = ");
  Serial.println(e);
  Serial.println("cm");

  //ketiga
  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration_2 = pulseIn(echoPin_2, HIGH);
  // Calculate the distance:
  k = duration_2 * 0.034 / 2;
  Serial.print(" ");
  Serial.println("Distance_2 = ");
  Serial.println(k);
  Serial.println("cm");
}