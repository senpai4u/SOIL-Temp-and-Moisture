#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2                  // Data wire is plugged into port 2 on the Arduino

OneWire oneWire(ONE_WIRE_BUS);          // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
 
DallasTemperature sensors(&oneWire);    // Pass our oneWire reference to Dallas Temperature.

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}

void loop() {
   Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  } 
  else
  {
    Serial.println("Error: Could not read temperature data");
  }

  // put your main code here, to run repeatedly:
int val;
  int mappedValue;
  val = analogRead(A0);
  Serial.print("Analog Value: " );
  Serial.println(val);
  
  mappedValue = map(val,322,667,100,0);
  Serial.print("Soil Moisture Percentage: ");
  Serial.println(mappedValue);
  
  delay(1000);
}
