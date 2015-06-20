#include<stdio.h>
#include<math.h>
# define n 3
void main()
{int i,j,k=1;
float x[n]={0,0,0},m[n]={0,0,0},s=1;
float a[n][n]={5,2,1,2,8,-3,1,-3,-6},d[n]={8,21,1};
  printf("高斯-塞德尔迭代法运算结果为:\n");
for(k=0;fabs(s-x[0])>1e-6;k++)
{
s=x[0];
for(i=0;i<n;i++)
 {m[i]=0;
 for(j=0;j<n;j++) m[i]=m[i]-a[i][j]*x[j];
  m[i]=m[i]+d[i]+a[i][i]*x[i];
  x[i]=m[i]/a[i][i];}
printf("Y1=%f Y2=%f Y3=%f\n",x[0],x[1],x[2]);
  } 
getchar() ;
}
