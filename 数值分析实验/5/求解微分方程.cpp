#include <stdio.h>
double meathod(double x,double y)
{
	double value;
	value=y-2.0*x/y;
	return value;
} 
void main()
{
	double k1,k2,k3,k4;
	double x[10],y[10];
	double h=0.2;
	int i;
	x[0]=0,y[0]=1.0;
	for(i=0;i<=5;i++)
	{
		x[i]=x[0]+i*h;
		k1=meathod(x[i],y[i]);
		k2=meathod((x[i]+1.0/2*h),(y[i]+1.0/2*h*k1));
		k3=meathod((x[i]+1/2.0*h),(y[i]+1/2.0*h*k2));
		k4=meathod((x[i]+h),(y[i]+h*k3));
		y[i+1]=y[i]+h/6*(k1+2*k2+2*k3+k4);
		printf("y=%lf\n",y[i]);
	
	}
}
