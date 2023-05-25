#include<Arduino.h>
int X,Y,Z,F;

void assign(int F){

	digitalWrite(13, F);
}

void setup(){

	pinMode(2,INPUT);
	pinMode(3,INPUT);
	pinMode(4,INPUT);
	pinMode(13,OUTPUT);
}

void loop(){

	X = digitalRead(2);  
	Y = digitalRead(3);  
	Z = digitalRead(4);
	F = (!Z&&Y)||(!X&&!Z);
        assign(F);
}
