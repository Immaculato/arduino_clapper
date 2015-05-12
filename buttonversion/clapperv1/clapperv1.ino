const int led = 13;
const int button = 7;
int val = 0;
int oldval = 0;
int state = 0;
int timespushed = 0;
int condition = 0;
unsigned long starttime = 0; 

void setup() {
  // set led and button pins to output/input
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  starttime = millis();
  // set val to button value
  while ((millis() - starttime) < 1000) {
    val = digitalRead(button);

  //check whether input is high and oldval is low
    if ((val == HIGH) && (oldval == LOW)) {
      timespushed = timespushed + 1;
      delay(75);
      
    }
  //wait because stupid button
    oldval = val;

  }

  
  delay(10);
  
  //store val to old value

    
    

    
  //turn on led if state is on, vice versa
    if ((condition == 0) && ((millis() - starttime) < 1000)){
      digitalWrite(led, HIGH);
      condition = 1 - condition;
    }
    else if ((condition == 1) && ((millis() - starttime) < 1000)) {
      digitalWrite(led, LOW);
      condition = 1 - condition;
    }
    timespushed = 0;
}
