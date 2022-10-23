#include "Adafruit_MAX31855.h"

#define MAXMISO 51
#define MAXCLK 52
#define MAXCS 53

Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXMISO);


void setup() {
  Serial.begin(9600);

  while (!Serial) delay(1); // wait for Serial on Leonardo/Zero, etc

  Serial.println("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
  Serial.print("Initializing sensor...");
  if (!thermocouple.begin()) {
    Serial.println("ERROR.");
    while (1) delay(10);
  }

  Serial.println("DONE.");

}

double c;

void loop() {
  c = thermocouple.readCelsius();
  Serial.println(thermocouple.readError());
  Serial.println(c);

}
