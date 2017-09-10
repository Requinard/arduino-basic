#include "Arduino.h"
#include "flash.h"
#include "wifi.h"
#include "settings.h"
#include "lightshow.h"
#include <ESP8266WiFi.h>
#define MAX_JOBS 3

struct JobHolder {
  void (*jobs[MAX_JOBS])() = {
    loopFlash,
    jobWifi,
    loopLightshow
  };
  short jobTimers[MAX_JOBS] = {10, 500, 50}; // Time in millis to trigger job at
  short timeSinceJob[MAX_JOBS] = {0}; // Keeps track of elapsed time since last job check
  short lastMillis = 0; // Track the last time we checked times
};

struct JobHolder jobs;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  Serial.println("Powering on suit");

  setupWifi();
  setupLightshow();
}

void loop(){
  // Get the current times
  // If last was 200 and it's 300 now, the diff is 100
  short now = millis();
  short timeDiff = now - jobs.lastMillis;

  jobs.lastMillis = now;

  for(int i = 0; i< MAX_JOBS; i++){
    // Update time diffs
    jobs.timeSinceJob[i] += timeDiff;

    // Check if triggered
    if(jobs.timeSinceJob[i] >= jobs.jobTimers[i]){
      // Execute job
      jobs.jobs[i]();

      // Reset counter
      jobs.timeSinceJob[i] = jobs.timeSinceJob[i] - jobs.jobTimers[i];
    }
  }
}
