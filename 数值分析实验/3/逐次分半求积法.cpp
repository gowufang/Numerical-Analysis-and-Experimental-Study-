#include <stdio.h>
#include <math.h>
double integral(
                double a,
                double b,
                double(*f)(double),
                double eps
                ) 
{
        double n = 1;
        double h = (b-a)/2;
        double Tn = h*(f(a)+f(b));
        double T2n = 0;
        while(1)
        {
                double sumf = 0;
				int i;
                for(i=1;i<=n;++i)sumf += f(a+(2*i-1)*h);
                T2n = Tn/2+h*sumf;
                if(fabs(T2n-Tn)<3*eps)break;
                Tn = T2n;
                n *= 2;
                h /= 2;
        }
        return T2n;
}
double func(double x)
{
	if(!x)return 1;
	else return (sin(x)/x);
}
int main()
{
        printf("%s%.7f\n","sin(x)/x在[0,1]的积分值为:",integral(0,1,func,1e-8));
        return 0;
}
