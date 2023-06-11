#include <Arduino.h>
boolean Z, Y, X, W, A, B, C, D;
void setup () {
pinMode (2, OUTPUT);
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
Z = 0;
Y = 0;
X = 0;
W = 0;
}
void loop () {
A = (!Z && !Y && !X && !W) || (!Z && !Y && X && !W) || (!Z && Y && !X && !W) || (!Z && Y && X && !W) || (Z && !Y && !X && !W);
B = (!Z && !Y && !X && W) || (!Z && !Y && X && !W) || (!Z && Y && !X && W) || (!Z && Y && X && !W);
C = (!Z && !Y && X && W) || (!Z && Y && !X && !W) || (!Z && Y && X && !W) || (!Z && Y && !X && W);
D = (W && X && Y && !Z) || (!W && !X && !Y && Z);
digitalWrite(5, D);
digitalWrite(4, C);
digitalWrite(3, B);
digitalWrite(2, A);
delay(500);
Z = D;
Y = C;
X = B;
W = A;
}
