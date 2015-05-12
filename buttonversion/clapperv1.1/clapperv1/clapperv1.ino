const int led = 13;
const int button = 7;
int val = 0;
int oldval = 0;
int timespushed = 0;
int condition = 0;
unsigned long starttime = 0; 

void setup() {
  // set led and button pins to output/input
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  //take the starting time
  starttime = millis();
  // check in the interval of about a second:
  while ((millis() - starttime) < 1200) {
    //is the button pushed?
    val = digitalRead(button);

  //check whether input is high and oldval is low (change in button condition)
    if ((val == HIGH) && (oldval == LOW)) {
      timespushed = timespushed + 1;
      
    }
  //set oldval to current val
    oldval = val;
  //debouncing makes no sense
    delay(20);

  }

  
  
  
  //store val to old value

    
    

    
  //turn on led if state is on and button is pushed >= twice, vice versa
    if ((condition == 0) && (timespushed==2)) {
      digitalWrite(led, HIGH);
      condition = 1 - condition;
    }
    else if ((condition == 1) && (timespushed==2)) {
      digitalWrite(led, LOW);
      condition = 1 - condition;
    }
    //reset times pushed
    timespushed = 0;
}
