#include "HX711.h"

// CIRCUIT:
// HX711 DOUT   TO PIN 2
// HX711 PD_SCK	TO PIN 3
//
// Pin definitions D2 and D3 are provided by "nodemcu" board,
// see `nodemcu/pins_arduino.h`.

HX711 scale;

void setup() {
  Serial.begin(57600);
  scale.begin(D2, D3);
}

void loop() {

  if ( scale.is_ready() ) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 was not found or not ready.");
  }

  delay(1000);
  
}
