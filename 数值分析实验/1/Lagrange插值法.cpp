#include<stdio.h>
#include<string.h>
main()
{ 
	int i,j,t=0;
 	double la=1,lb=1,x=0.596,lk,ln=0;
	double a[6]={0.4,0.55,0.65,0.8,0.9,1.05};
    double b[6]={0.41075,0.57815,0.69675,0.88811,1.02652,1.25382};
	printf("所求的x的值为：%f\n",x);
    for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(j==t)continue;
			la=la*(x-a[j]);
			lb=lb*(a[t]-a[j]);
            
		}
		t++;
		lk=la/lb;
		ln=ln+lk*b[i];
		la=1;
		lb=1;
	}
	printf("%f用lagrange的差值算法算出的值为：%f\n",x,ln);

}
