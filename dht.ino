#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN D1 

#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Test!");
  dht.begin();
}

void loop() {
  delay(2000);  

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if(isnan(h) || isnan(t)  || isnan(f)) 
  {
    Serial.println("Failed to Read DHT sensor");
    return;
  }

  Serial.print(" Humidity: ");
  Serial.println(h);

  Serial.print(" Temperature: ");
  Serial.print(t);
  Serial.println("'c");

  Serial.print(" Temperature: ");
  Serial.print(f);
  Serial.println("'F");

}
