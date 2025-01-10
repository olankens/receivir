#include <IRremote.h>

IRrecv irrecv(11);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void dump(decode_results *results) {
  for (int i = 1; i < results->rawlen; i++) {
    int payload = (int)results->rawbuf[i] * USECPERTICK;
    Serial.print(payload, DEC);
    Serial.print(", ");
  }
  Serial.println("\n");
}

void loop() {
  if (irrecv.decode(&results)) {
    dump(&results);
    irrecv.resume();
  }
}