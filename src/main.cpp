#include "Arduino.h"
#include "flash.h"

#define MAX_JOBS 2

struct JobHolder {
  void (*jobs[MAX_JOBS])() = {IAmAJob, IAmASecondJob};
  short jobTimers[MAX_JOBS] = {2000, 10000}; // Time in millis to trigger job at
  short timeSinceJob[MAX_JOBS] = {0};
  short lastMillis = 0;
};

struct JobHolder jobs;

void setup(){
  Serial.begin(9600);
  Serial.println("Setting up arduino");
  Serial.printf("Last millis is %f\n", jobs.lastMillis);
}

void loop(){
  // Get the current times
  // If last was 200 and it's 300 now, the diff is 100
  short now = millis();
  short timeDiff = now - jobs.lastMillis;
  jobs.lastMillis = now;

  // Update the job timers
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
