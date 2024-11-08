/* File: ESP32_DailyStruggle
 *  For exeresizing the switches on the "homeWork2" assembly at: 
 *  https://github.com/nk25719/PMD___aka-KiCad-esp32-6leds-2switches-1pj-circuit-
 *  
 *  Author: Forrest Lee Erickson
 *  Date: 20241108
 *  License: Dedicated to the public domain
 *  
*/

#define PROG_NAME "ESP32_DailyStruggle"
#define BAUDRATE 115200
#define LED_BUILTIN  2    // ESP32 Kit//const int LED_BUILTIN = 13;    //Not really needed for Arduino UNO it is defined in library

#include <DailyStruggleButton.h>

// Pins for switches
//const int switchPin1 = 36; // Switch 1 connected to GPIO 36 Reference  S1-morseCodeDanger1
//const int switchPin2 = 39; // Switch 2 connected to GPIO 39 Reference  S2-RepeatCalculation1
//const int switchPin3 = 34; // Switch 3 connected to GPIO 34 Reference  S3-muteFiveMin1
//const int switchPin4 = 35; // Switch 4 connected to GPIO 35 Reference  S4-SendEmergMessage1

#define SWITCH_RepeatCalculation 39
#define SWITCH_MUTE 34

DailyStruggleButton muteButton;
// Time in ms you need to hold down the button to be considered a long press
unsigned int longPressTime = 1000;
// How many times you need to hit the button to be considered a multi-hit
byte multiHitTarget = 2;
// How fast you need to hit all buttons to be considered a multi-hit
//unsigned int multiHitTime = 400;
unsigned int multiHitTime = 800;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);
  pinMode(SWITCH_RepeatCalculation, INPUT_PULLUP); //The on HMWK
  //Serial setup
  delay(100);
  Serial.begin(BAUDRATE);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  delay(500);
  serialSplash();

  // Use set(digital pin connected to button, a callback function, type of pull-up/down) to initialise the button
  // Choose between INT_PULL_UP, EXT_PULL_UP and EXT_PULL_DOWN
  muteButton.set(SWITCH_MUTE, muteButtonCallback, INT_PULL_UP);
  
  // You can enable long press to use this feature
  muteButton.enableLongPress(longPressTime);

  // You can enable multi-hit to use this feature
  muteButton.enableMultiHit(multiHitTime, multiHitTarget);

  digitalWrite(LED_BUILTIN, LOW);
}//end of setup()

void loop() {
  // put your main code here, to run repeatedly:
  muteButton.poll();

  if (!digitalRead(SWITCH_RepeatCalculation)) {
    Serial.println("SWITCH_RepeatCalculation pressed");
  }

  delay(100);
}//end of loop()

void serialSplash(void) {
  //Serial splash
  Serial.println(F("==================================="));
  ////  Serial.println(MODEL_NAME);
  //  Serial.println(DEVICE_UNDER_TEST);
  Serial.println(PROG_NAME);
  //  Serial.println(FIRMWARE_VERSION);
  //  Serial.println(HARDWARE_VERSION);
  //  Serial.print("Builtin ESP32 MAC Address: ");
  //  Serial.println(myMAC);
  //  Serial.print(F("Alarm Topic: "));
  //  Serial.println(subscribe_Alarm_Topic);
  //  Serial.print(F("Broker: "));
  //  Serial.println(mqtt_server);
  Serial.print(F("Compiled at: "));
  Serial.println(F(__DATE__ " " __TIME__));  //compile date that is used for a unique identifier
  //  Serial.println(LICENSE);
  Serial.println(F("==================================="));
  Serial.println();
}//end Serial Splash

// This function will be called whenever an event occurs.
// We pass the name of this callback function in set().
// It needs to take a parameter of the byte datatype.
// This byte will indicate the event.
// It needs to return void.
void muteButtonCallback(byte btnStatus) {
  switch (btnStatus) {
    case onPress:
      // Do something...
      //      local_ptr_to_serial->println(F("SWITCH_MUTE onPress"));
      Serial.println("SWITCH_MUTE onPress ");
      //      currentlyMuted = !currentlyMuted;
      //      start_of_song = millis();
      //      annunciateAlarmLevel(local_ptr_to_serial);
      //      printAlarmState(local_ptr_to_serial);
      break;

    // onRelease is indicated when the button is let go
    case onRelease:
      Serial.println("Button Released");
      break;

    // onLongPress is indidcated when you hold onto the button
    // more than longPressTime in milliseconds
    case onLongPress:
      Serial.print("Buttong Long Pressed For ");
      Serial.print(longPressTime);
      Serial.println("ms");
      break;

    // onMultiHit is indicated when you hit the button
    // multiHitTarget times within multihitTime in milliseconds
    case onMultiHit:
      Serial.print("Button Pressed ");
      Serial.print(multiHitTarget);
      Serial.print(" times in ");
      Serial.print(multiHitTime);
      Serial.println("ms");
      break;
  }
}//end my button
