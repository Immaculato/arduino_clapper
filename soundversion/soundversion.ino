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
//test change v001
void loop()
{
  //take the starting time
  
  Serial.begin(9600);
  oldval = LOW;
  //starting from when the button is first pushed:
  val = digitalRead(button);
  if ((val == HIGH) && (oldval == LOW))
    {
      starttime = millis();
    //listen for 1 second total to see how many times noise is heard
    while ((millis() - starttime) < 1500)
    {
      val = digitalRead(button);
      if ((val == HIGH) && (oldval == LOW))
      {
        timespushed = timespushed + 1;
        Serial.print("clap ");
        
      }
    //set oldval to current val
      oldval=val;
      delay(50);
    }
  }





  //turn on led if state is on and button is pushed twice, vice versa
  if ((condition == 0) && (timespushed == 2))
  {
    digitalWrite(led, HIGH);
    condition = 1 - condition;
  }
  else if ((condition == 1) && (timespushed == 2))
  {
    digitalWrite(led, LOW);
    condition = 1 - condition;
  }
  //reset times pushed
  timespushed = 0;
}
