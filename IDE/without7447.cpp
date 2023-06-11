boolean Z, Y, X, W, a, b, c, d, e, f, g, A, B, C, D;
void setup () {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
A = 0;
B = 0;
C = 0;
D = 0;
}
void loop () {
a = ! ( (!A && !B && !C && D) || (!A && !B && C && !D) || (!A && B && !C && !D) || (!A && B && !C && D) || (!A && B && C && !D) || (!A && B && C && D) || (A && !B && !C && !D) || (A && !B && !C && D) );
b = ! ( (!A && !B && !C && !D) || (!A && !B && !C && D) || (!A && !B && C && !D) || (!A && !B && C && D) || (!A && B && C && !D) || (!A && B && C && D) || (A && !B && !C && !D) || (A && !B && !C && D) ) ;
c = ! ( (!A && !B && !C && !D) || (!A && !B && C && !D) || (!A && !B && C && D) || (!A && B && !C && !D) || (!A && B && !C && D) || (!A && B && C && !D) || (!A && B && C && D) || (A && !B && !C && !D) || (A && !B && !C && D) ) ;
d = ! ( (!A && !B && !C && D) || (!A && !B && C && !D) || (!A && B && !C && !D) || (!A && B && !C && D) || (!A && B && C && D) || (A && !B && !C && D) ) ;
e = ! ( (!A && !B && !C && D) || (!A && B && !C && D) || (!A && B && C && D) || (A && !B && !C && D) ) ;
f = ! ( (!A && !B && C && D) || (!A && B && !C && !D) || (!A && B && !C && D) || (!A && B && C && D) || (A && !B && !C && !D) || (A && !B && !C && D) ) ;
g = ! ( (!A && !B && !C && D) || (!A && !B && C && !D) || (!A && !B && C && D) || (!A && B && !C && !D) || (!A && B && !C && D) || (!A && B && C && D) || (A && !B && !C && !D) ) ;

W = (!A && !B && !C && !D) || (!A && !B && C && !D) || (!A && B && !C && !D) || (!A && B && C && !D) || (A && !B && !C && !D) ;
X = (!A && !B && !C && D) || (!A && !B && C && !D) || (!A && B && !C && D) || (!A && B && C && !D) ;
Y = (!A && !B && C && D) || (!A && B && !C && !D) || (!A && B && C && !D) || (!A && B && !C && D) ;
Z = (D && C && B && !A) || (!D && !C && !B && A) ;

digitalWrite(8, g);
digitalWrite(7, f);
digitalWrite(6, e);
digitalWrite(5, d);
digitalWrite(4, c);
digitalWrite(3, b);
digitalWrite(2, a);
delay(500);

D = W;
C = X;
B = Y;
A = Z;
}
