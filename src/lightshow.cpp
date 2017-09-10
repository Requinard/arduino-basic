#include "lightshow.h"
#include "settings.h"

extern struct Settings settings;

void setupLightshow(){
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
}

void loopLightshow(){
  runCheeks();

  digitalWrite(D4, 255);
  digitalWrite(D3, 255);
  digitalWrite(D2, 255);
}

void runCheeks(){
  RGB* target = &settings.cheeks.target;
  RGB* current = &settings.cheeks.current;

  moveTo(D4,&(target->r), &(current->r));
  moveTo(D3,&(target->g), &(current->g));
  moveTo(D2,&(target->b), &(current->b));
}

void moveTo(int pin, unsigned char* target,unsigned char* current){
  if(*target != *current){
    int delta = *target - *current;

    Serial.printf("Pin %d\tTarget %d\tCurrent %d\tDelta %d\n", pin,*target, *current, delta);

    if(delta>9){
      analogWrite(pin, *current + 10);
      *current += 10;
    } else if(delta<-9){
      analogWrite(pin, *current - 10);
      *current -= 10;
    } else {
      analogWrite(pin, *current + delta);
      *current += delta;
    }
  }
}
