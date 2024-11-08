//#define RepeatCalculation 39
//#define SWITCH_MUTE 34
//#define morseCodeDanger 36
//#define SendEmergMessage 35



// This function will be called whenever an event occurs.
// We pass the name of this callback function in set().
// It needs to take a parameter of the byte datatype.
// This byte will indicate the event.
// It needs to return void.

void SendEmergMessageCallback(byte btnStatus) {
  switch (btnStatus) {
    case onPress:
      // Do something...
      //      local_ptr_to_serial->println(F("SWITCH_MUTE onPress"));
      Serial.println("SendEmergMessage onPress ");
      //      currentlyMuted = !currentlyMuted;
      //      start_of_song = millis();
      //      annunciateAlarmLevel(local_ptr_to_serial);
      //      printAlarmState(local_ptr_to_serial);
      break;

    // onRelease is indicated when the button is let go
    case onRelease:
      Serial.println("SendEmergMessage Released");
      break;

    // onLongPress is indidcated when you hold onto the button
    // more than longPressTime in milliseconds
    case onLongPress:
      Serial.print("SendEmergMessage Button Long Pressed For ");
      Serial.print(longPressTime);
      Serial.println("ms");
      break;

    // onMultiHit is indicated when you hit the button
    // multiHitTarget times within multihitTime in milliseconds
    case onMultiHit:
      Serial.print("SendEmergMessage Button Pressed ");
      Serial.print(multiHitTarget);
      Serial.print(" times in ");
      Serial.print(multiHitTime);
      Serial.println("ms");
      break;
  }
}//end SendEmergMessageCallback

void RepeatCalculationCallback(byte btnStatus) {
  switch (btnStatus) {
    case onPress:
      // Do something...
      //      local_ptr_to_serial->println(F("SWITCH_MUTE onPress"));
      Serial.println("RepeatCalculation onPress ");
      //      currentlyMuted = !currentlyMuted;
      //      start_of_song = millis();
      //      annunciateAlarmLevel(local_ptr_to_serial);
      //      printAlarmState(local_ptr_to_serial);
      break;

    // onRelease is indicated when the button is let go
    case onRelease:
      Serial.println("RepeatCalculation Released");
      break;

    // onLongPress is indidcated when you hold onto the button
    // more than longPressTime in milliseconds
    case onLongPress:
      Serial.print("RepeatCalculation Button Long Pressed For ");
      Serial.print(longPressTime);
      Serial.println("ms");
      break;

    // onMultiHit is indicated when you hit the button
    // multiHitTarget times within multihitTime in milliseconds
    case onMultiHit:
      Serial.print("RepeatCalculation Button Pressed ");
      Serial.print(multiHitTarget);
      Serial.print(" times in ");
      Serial.print(multiHitTime);
      Serial.println("ms");
      break;
  }
}//end RepeatCalculationCallback


void muteButtonCallback(byte btnStatus) {
  switch (btnStatus) {
    case onPress:
      // Do something...
      //      local_ptr_to_serial->println(F("SWITCH_MUTE onPress"));
      Serial.println("muteButton onPress ");
      //      currentlyMuted = !currentlyMuted;
      //      start_of_song = millis();
      //      annunciateAlarmLevel(local_ptr_to_serial);
      //      printAlarmState(local_ptr_to_serial);
      break;

    // onRelease is indicated when the button is let go
    case onRelease:
      Serial.println("muteButton Released");
      break;

    // onLongPress is indidcated when you hold onto the button
    // more than longPressTime in milliseconds
    case onLongPress:
      Serial.print("muteButton Button Long Pressed For ");
      Serial.print(longPressTime);
      Serial.println("ms");
      break;

    // onMultiHit is indicated when you hit the button
    // multiHitTarget times within multihitTime in milliseconds
    case onMultiHit:
      Serial.print("muteButton Button Pressed ");
      Serial.print(multiHitTarget);
      Serial.print(" times in ");
      Serial.print(multiHitTime);
      Serial.println("ms");
      break;
  }
}//end muteButtonCallback

void morseCodeDangerCallback(byte btnStatus) {
  switch (btnStatus) {
    case onPress:
      // Do something...
      //      local_ptr_to_serial->println(F("SWITCH_MUTE onPress"));
      Serial.println("morseCodeDanger onPress ");
      //      currentlyMuted = !currentlyMuted;
      //      start_of_song = millis();
      //      annunciateAlarmLevel(local_ptr_to_serial);
      //      printAlarmState(local_ptr_to_serial);
      break;

    // onRelease is indicated when the button is let go
    case onRelease:
      Serial.println("morseCodeDanger Released");
      break;

    // onLongPress is indidcated when you hold onto the button
    // more than longPressTime in milliseconds
    case onLongPress:
      Serial.print("morseCodeDanger Button Long Pressed For ");
      Serial.print(longPressTime);
      Serial.println("ms");
      break;

    // onMultiHit is indicated when you hit the button
    // multiHitTarget times within multihitTime in milliseconds
    case onMultiHit:
      Serial.print("morseCodeDanger Button Pressed ");
      Serial.print(multiHitTarget);
      Serial.print(" times in ");
      Serial.print(multiHitTime);
      Serial.println("ms");
      break;
  }
}//end morseCodeDangerCallback
