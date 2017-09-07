#include "Arduino.h"
#include "flash.h"
#include "wifi.h"
#include <ESP8266WiFi.h>
#define MAX_JOBS 2

struct JobHolder {
  void (*jobs[MAX_JOBS])() = {
    IAmAJob,
    jobWifi
  };
  short jobTimers[MAX_JOBS] = {2000, 500}; // Time in millis to trigger job at
  short timeSinceJob[MAX_JOBS] = {0}; // Keeps track of elapsed time since last job check
  short lastMillis = 0; // Track the last time we checked times
};

struct JobHolder jobs;

void setup(){
  Serial.begin(115200);
  Serial.println("Setting up arduino");
  Serial.printf("Last millis is %f\n", jobs.lastMillis);
  setupWifi();
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
