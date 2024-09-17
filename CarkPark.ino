#define echoPin 2
#define trigPin 3
#define Sound 7

long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(Sound, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by setting the trigPin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the duration of the pulse from the echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance = duration * 0.034 / 2;
  
  // Output the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Control the Sound based on the distance
  if (distance < 80) {
    digitalWrite(Sound, HIGH);
  } else {
    digitalWrite(Sound, LOW);
  }
  
  // Delay before the next measurement
  delay(1000);
}
