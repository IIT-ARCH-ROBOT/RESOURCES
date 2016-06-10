// Digital IO w a button

Timer flashTimer(100, flash);
int buttonState = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int toggleState = 0;

void setup() {
    pinMode(0, INPUT_PULLDOWN);
    pinMode(7, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    //debounce switch
    buttonState1 = digitalRead(0);
    delay(5);
    buttonState2 = digitalRead(0);
    //toggle
    if(buttonState1 == buttonState2){
        buttonState = buttonState2;
    }
    
    if(buttonState == 1){
        if(toggleState == 0){
            toggleState = 1;
            flashTimer.start();
        }
        else if(toggleState == 1){
            toggleState = 0;
            flashTimer.stop();
        }
    }
    
    Serial.println("buttonState: "+String(buttonState)+" toggleState: "+String(toggleState)+" timer: ");
}

void flash(){
    digitalWrite(7, HIGH);
    delay(50);
    digitalWrite(7, LOW);
}
