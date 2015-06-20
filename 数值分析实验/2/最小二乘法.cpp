#include<iostream>
#include<math.h>
using namespace std;
#define N 5
#define M 2 
main()
{
	int i,j,k,l,m;
	int x[N]={1,2,3,4,5};
	double y[N]={4,4.5,6,8,8.5};
	double w[N]={2,1,3,1,1};
	double c[M][M],d[1][M];
	double a,b,t=0;
	for(i=0;i<M;i++)
	   for(j=0;j<M;j++)
	   {
	      for(k=0;k<N;k++)
			  t+=w[k]*pow(x[k],j)*pow(x[k],i);
		  c[i][j]=t;
		  t=0;
	   }
        
	    
	for(l=0;l<M;l++)
	{
		for(m=0;m<N;m++)
			t+=w[m]*y[m]*pow(x[m],l);  
		d[0][l]=t;
		t=0;
	}
    a=(d[0][1]-c[1][1]*d[0][0]/c[0][1])/(c[1][0]-c[1][1]*c[0][0]/c[0][1]);
	b=(d[0][0]-c[0][0]*a)/c[0][1];
	cout<<"y="<<a<<"+"<<b<<"x"<<endl;

}  	  
