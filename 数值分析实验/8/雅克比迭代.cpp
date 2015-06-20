#include "stdio.h"
#include "math.h"
#include "string.h"
main()  
{
int i,j,k;
float m1=0.0,m2=0.0;
float a[3][4]={5,2,1,8,2,8,-3,21,1,-1,-1,1};
float x[3]={0.0,0.0,0.0};
for(k=1;k<=20;)
    {for(i=0;i<=2;i++)
      {
         for(j=0;j<i;j++)
          m1=m1+a[i][j]*x[j];
         for(j=i+1;j<=2;j++)
          m2=m2+a[i][j]*x[j];
          x[i]=(a[i][3]-m1-m2)/a[i][i];
		  m1=0,m2=0;
       }
     k++;                                                                                                                                                                                           
    }
printf("ÑÅ¿É±Èµü´ú·¨¼ÆËã½á¹ûÎª£º\n");
for(i=0;i<=2;i++)
printf("x[%2d]=%8.9f\n",i+1,x[i]);
}
