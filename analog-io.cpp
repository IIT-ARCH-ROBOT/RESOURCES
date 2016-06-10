int adcVal = 0;
int dacVal = 0;

void setup() {
    RGB.control(true);
    RGB.color(255,255,0);
}

void loop() {
    adcVal = analogRead(0);
    dacVal = map(adcVal, 0, 4095, 0, 255);
    //dacVal = constrain(adcVal, 0, 255);
    RGB.brightness(dacVal);
}
