#include "Arduino.h"
#include "flash.h"

#define SAMPLE_COUNT 50
#define PHOTORESISTOR_PIN A0 // Connect parrallel to 3.3V and 10K
#define THRESHOLD 15
#define DEBUG false

short samples[SAMPLE_COUNT];
short lastIndex = 0;
short lastValue = 0;

void setupFlash(){
  // Set up the flash input
  pinMode(PHOTORESISTOR_PIN, INPUT_PULLUP);
  // setup array basically
  short val = analogRead(PHOTORESISTOR_PIN)/4;

  for(int i = 0; i < SAMPLE_COUNT; i++){
    samples[i] = val;
  }
}

void loopFlash(){
  float avg = samples[0];

  // Read current value
  short val = analogRead(PHOTORESISTOR_PIN)/4;

  samples[lastIndex++] = val;

  if(lastIndex >= SAMPLE_COUNT) lastIndex = 0;

  // calculate average over samples
  for(int i = 0; i < SAMPLE_COUNT; i++){
    avg = (avg + samples[i]) / 2.0;
  }
  
  if(DEBUG){
    Serial.print("Pin value is ");
    Serial.print(val);
    Serial.print("\t Average value is");
    Serial.print(avg);
    Serial.print('\n');
  }

  if(val -avg >= THRESHOLD){
    Serial.println("AVG exceeded threshold");

    // do shit here
  }
}
