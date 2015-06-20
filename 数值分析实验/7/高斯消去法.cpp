#include <stdio.h>
#include <stdlib.h> 
#define N 10 //矩阵大小范围
/** 使用已经求出的x，向前计算x（供getx()调用）* float a[][]    系数矩阵* float x[]        方程组解* int    i        解的序号* int    n        矩阵大小* return        公式中需要的和*/
float getm(float a[N][N], float x[N], int i, int n)
{float m = 0;
    int r;
    for(r=i+1; r<n; r++)
    {m += a[i][r] * x[r];
    }
    return m;
}
/** 解方程组，计算x* float a[][]    系数矩阵* float b[]        右端项    * float x[]        方程组解* int    i        解的序号* int    n        矩阵大小* return        方程组的第i个解*/
float getx(float a[N][N], float b[N], float x[N], int i, int n)
{float result;
    if(i==n-1) //计算最后一个x的值
        result = float(b[n-1]/a[n-1][n-1]);
    else //计算其他x值（对于公式中的求和部分，需要调用getm()函数）
        result = float((b[i]-getm(a,x,i,n))/a[i][i]);
    return result;
}
void main()
{
    //float a[N][N] = {{2,1,1},{1,3,2},{1,2,2}};
    //float b[N] = {4,6,5};
    float a[N][N];  //系数矩阵
    float b[N]; //右端项
    float x[N]; //方程组解
    int i,j,k;
    int n=N; //矩阵大小 /*用户手工输入矩阵*/
    printf("请输入系数矩阵的大小：");
    scanf("%d", &n);
    printf("请连续输入矩阵值：");
    for(i=0; i<n; i++)
    {for(j=0; j<n; j++)
        scanf("%f", &a[i][j]);
    }
    printf("请输入右端项：");
    for(i=0; i<n; i++)
    {scanf("%f", &b[i]);
    }/*显示原始矩阵*/
    printf("\n原始矩阵\n");
    for(i=0; i<n; i++)
    {for(j=0; j<n; j++)
            printf("%f  ",a[i][j]);
        printf("\t|\t%f\n",b[i]);
    }printf("\n\n");/*进行高斯消去*/
    for(j=0; j<n-1; j++)
    {for(i=j+1; i<n; i++)
        {float m = (float)(a[i][j]/a[j][j]);
            for(k=j; k<n; k++)
            {a[i][k] = a[i][k]-m*a[j][k];
            }
            b[i] = b[i]-m*b[j];
        }
} /*显示处理后矩阵*/
    printf("高斯消去后矩阵\n");
    for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
            printf("%f  ",a[i][j]);
        printf("\t|\t%f\n",b[i]);
}/*回代方式解方程组*/
    for(i=n-1; i>=0; i--)
{x[i] = getx(a,b,x,i,n);
}/*显示方程组解*/
    printf("\n\n方程组解\n");
    for(i=0; i<n; i++)
{
printf("x%d = %f\n", i+1,x[i]);
    }
}
