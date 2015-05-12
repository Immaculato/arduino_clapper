const int led = 13;
const int button = 7;
int val = 0;
int oldval = 0;
int state = 0;
int timespushed = 0;
int condition = 0;
unsigned long starttime = 0; 
bool doubleflag = 0;

void setup() {
  // set led and button pins to output/input
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  starttime = millis();
  // set val to button value
  while ((timespushed < 2) and ((millis() - starttime) < 1000)) {
    val = digitalRead(button);

  //check whether input is high and oldval is low
    if ((val == HIGH) && (oldval == LOW)) {
      timespushed = timespushed + 1;
      delay(10);
    }
    
    if (timespushed == 2) {
      doubleflag == 1;
    }
    else {
      doubleflag == 0;
    }
  //wait because stupid button
    oldval = val;

  }

  
  delay(10);
  
  //store val to old value

    
    

    
  //turn on led if state is on, vice versa
    if (doubleflag){
      digitalWrite(led, HIGH);
    }
    
    else {
      digitalWrite(led, LOW);
    }
    timespushed = 0;
}
