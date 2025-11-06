int red = 9;
int green = 7;
int sensor = 10;

int redLightTime = 10000;
int greenLightTime = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(sensor, INPUT);

  digitalWrite(red, HIGH);
}

void cycle_lights() {
  // delay(redLightTime);
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
  int sensorState = digitalRead(sensor);
  if (sensorState == 1) {
    cycle_lights();
    digitalWrite(red, HIGH);
  }
  delay(500);
}
