int led = PIN_LED;


void setup() {
 pinMode(led,OUTPUT)
 Serial.begin(115200)
}

void loop() {
  Serial.println("Test");
  digitalWrite(led,HIGH);
}
