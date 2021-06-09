int temt6000Pin = A0;// Analog pin for reading sensor data
int led = D7;
float light;
int light_value;
void setup() {
  Serial.begin(9600);
  pinMode(temt6000Pin, INPUT); //data pin for ambientlight sensor
  pinMode(led, OUTPUT);
}

void loop() {
  int light_value = analogRead(temt6000Pin);
  light = light_value * 0.0976;// percentage calculation 
  Serial.println(light);
  if (light_value > 1000) {
    digitalWrite(led, HIGH);
    Particle.publish("Light_status_on","on");}
  else if (light_value < 1000) {
      digitalWrite(led,LOW);
      Particle.publish("Light_status_off","off");}
      delay(5000);
}
