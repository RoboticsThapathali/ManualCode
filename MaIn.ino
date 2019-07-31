/*
*	Author - Rabin Nepal 
*	
*	this is code for arduino to interface the reciever 
* receiver -> flysky reciever with I bus capabities 
*	transmitter -> any transmitter of Flysky
*/



#include "ibus.h"

uint16_t channel[10];


void setup() {
  Serial.begin(115200);
  IBus.begin(Serial); 
}
void loop() {
  readData();
  printCheck();
}

void readData() {
  IBus.loop();
  for (int i = 0; i < 10; i++) {
    channel[i] = IBus.readChannel(i);
  }
}

void printCheck() {
  Serial.print(channel[0]);
  Serial.print(" - ");
  Serial.print(channel[1]);
  Serial.print(" - ");
  Serial.print(channel[2]);
  Serial.print(" - ");
  Serial.print(channel[3]);
  Serial.print(" - ");
  Serial.print(channel[4]);
  Serial.print(" - ");
  Serial.print(channel[5]);
  Serial.print(" - ");
  Serial.print(channel[6]);
  Serial.print(" - ");
  Serial.print(channel[7]);
  Serial.print(" - ");
  Serial.print(channel[8]);
  Serial.print(" - ");
  Serial.println(channel[9]);
}
