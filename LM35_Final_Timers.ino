#include <TimerOne.h> //Using Timers to provide delays
//Temperature Sensor and LED Pin Declaration
#define lm35 A0
#define LED 13
int blinkInterval = 250;//default  provided in attachInterrupt function
void setup()
{
  pinMode(lm35, INPUT);
  pinMode(LED, OUTPUT);
  Timer1.initialize(blinkInterval);  // Initialize Timer1 with a default Interval
  Timer1.attachInterrupt(timerISR);  // Attach the ISR function to Timer1
  Serial.begin(9600);
}

void loop()
{
  int lm35_read = analogRead(lm35);
  
  // Convert the reading into voltage(millivolts to volts):
  float voltage = (lm35_read /1024.0)*5000;

  // Convert the voltage into the temperature in degree Celsius:
  float temperature = voltage / 10;

  // Print the temperature in the Serial Monitor:
  Serial.print(temperature);
  Serial.println(" C");
  //Temperature Condition check
  if(temperature >= 30.0)
  {
    blinkInterval = 500;

  }
  else
  {
    blinkInterval = 250;
  }
}
void timerISR(){
  static boolean ledState = LOW;

  // Toggle LED state
  ledState = !ledState;
  digitalWrite(LED, ledState);
}
