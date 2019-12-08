#include <DHTesp.h>

#define pin 25

DHTesp dht;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.setup(pin, DHTesp::DHT11);
}

void loop() {
  // put your main code here, to run repeatedly:
  String out = "";
  TempAndHumidity lastValues = dht.getTempAndHumidity();
  out = out + String(lastValues.temperature) + "/" + String(lastValues.humidity);
  Serial.println(out);
  delay(2000);
}
