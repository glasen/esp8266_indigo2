#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "AudioFileSourcePROGMEM.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"
#include "impact.h"

AudioGeneratorWAV *wav;
AudioFileSourcePROGMEM *file;
AudioOutputI2S *out;

void setup()
{
  WiFi.mode(WIFI_OFF); 
  delay(5000);
  audioLogger = &Serial;
  file = new AudioFileSourcePROGMEM( impact, sizeof(impact) );
  out = new AudioOutputI2S();
  wav = new AudioGeneratorWAV();
  wav->begin(file, out);
}

void loop()
{
  if (wav->isRunning()) {
    if (!wav->loop()) wav->stop();
  } else {
    delay(1000);
  }
}
