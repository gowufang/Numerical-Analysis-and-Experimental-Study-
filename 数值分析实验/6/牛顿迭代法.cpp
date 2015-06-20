#include"math.h"
#include<stdio.h>
void main()
{ 
float x,x0,f,f1;  x=1.5;
do{
x0 = x;
f = 2 * x0 * x0 * x0 - 4 * x0 * x0 + 3 * x0 -6;
f1 = 6 * x0 * x0 - 8 * x0 + 3;
x = x0 - f/f1;
}
while(fabs(x - x0) >= 1e - 5);
printf("%f/n",x);
}
