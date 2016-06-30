Timer tempTimer(2000, publishTemp);
Servo myServo;

int val = 0;
float voltage = 0.0;
float temperatureC = 0.0;
int servoPos = 0;

void setup() {
    pinMode(A0, INPUT);
    pinMode(D0, OUTPUT);
    Serial.begin(9600);
    tempTimer.start();
    myServo.attach(D0);
}

void loop() {
    val = analogRead(A0);
    voltage = val*(3.3/4096.0);
    Serial.print("Voltage = ");
    Serial.print(voltage);
    temperatureC = (voltage - 0.5) * 100;
    servoPos = map(temperatureC, 0, 100, 5,175);
    myServo.write(servoPos);
    Serial.print(" Temperature = ");
    Serial.print(temperatureC);
    Serial.println(" C");
    delay(100);
}

void publishTemp(){
    Particle.publish("TEMPC", String(temperatureC));
}
