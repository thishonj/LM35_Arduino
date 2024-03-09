
//Temperature Sensor and LED Pin Declaration
#define lm35 A0
#define LED 13
void setup()
{
  pinMode(lm35, INPUT);
  pinMode(LED, OUTPUT);
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
  if(temperature >= 30.0)
  {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  }
  else
  {
  digitalWrite(LED, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  delay(250);
  }
}