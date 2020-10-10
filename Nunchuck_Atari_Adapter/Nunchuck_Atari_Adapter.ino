#include <NintendoExtensionCtrl.h>

#define U_PIN 0
#define D_PIN 1
#define L_PIN 2
#define R_PIN 3
#define F_PIN 10

NESMiniController nes;

void setup() {
  //Serial.begin(115200);
  nes.begin();

  while (!nes.connect()) {
    //Serial.println("Classic Controller not detected!");
    delay(1000);
  }

  pinMode(U_PIN, OUTPUT);
  pinMode(D_PIN, OUTPUT);
  pinMode(L_PIN, OUTPUT);
  pinMode(R_PIN, OUTPUT);
  pinMode(F_PIN, OUTPUT);

  digitalWrite(U_PIN, LOW);
  digitalWrite(D_PIN, LOW);
  digitalWrite(L_PIN, LOW);
  digitalWrite(R_PIN, LOW);
  digitalWrite(F_PIN, LOW);
}

void loop() {
  bool success = nes.update();  // Get new data from the controller

  if (success == true) {  // We've got data!
    //nes.printDebug();  // Print all of the values!
    digitalWrite(U_PIN, (nes.dpadUp() || nes.buttonA()));
    digitalWrite(D_PIN, nes.dpadDown());
    digitalWrite(L_PIN, nes.dpadLeft());
    digitalWrite(R_PIN, nes.dpadRight());
    digitalWrite(F_PIN, nes.buttonB());
  } else {  // Data is bad :(
    //Serial.println("Controller Disconnected!");
    delay(1000);
    nes.connect();
  }
}
