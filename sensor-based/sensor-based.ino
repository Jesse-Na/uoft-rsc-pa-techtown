int red = 9;
int green = 7;
int sensor = 10;

int sensorState = LOW;
int greenLightTime = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(sensor, INPUT);

  digitalWrite(red, HIGH);
}
void cycle_lights() {
  // switch from red to green
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(green, HIGH);

  delay(greenLightTime);

  // switch from green to red
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(sensor);

  if (reading == HIGH) {
    // reading will be high on object entry and exit,
    // but we don't want to cycle lights on consecutive HIGHs.
    if (sensorState == LOW) {
      cycle_lights();
      sensorState = HIGH;
    }
  } else {
    sensorState = LOW;
  }

}