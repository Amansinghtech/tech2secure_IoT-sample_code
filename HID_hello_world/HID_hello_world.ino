/**
 * Made with Duckuino, an open-source project.
 * Check the license at 'https://github.com/Dukweeno/Duckuino/blob/master/LICENSE'
 */

#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(3000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(1000);
  Keyboard.print(F("notepad"));

  typeKey(KEY_RETURN);

  delay(500);
  Keyboard.print(F("welcome to tech2secure Internet of Things course"));

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
