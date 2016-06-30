Timer tempTimer(2000, publishTemp);

int val = 0;
float voltage = 0.0;
float temperatureC = 0.0;

void setup() {
    pinMode(A0, INPUT);
    Serial.begin(9600);
    tempTimer.start();
}

void loop() {
    val = analogRead(A0);
    voltage = val*(3.3/4096.0);
    Serial.print("Voltage = ");
    Serial.print(voltage);
    temperatureC = (voltage - 0.5) * 100;
    Serial.print(" Temperature = ");
    Serial.print(temperatureC);
    Serial.println(" C");
    delay(100);
}

void publishTemp(){
    Particle.publish("TEMPC", String(temperatureC));
}
