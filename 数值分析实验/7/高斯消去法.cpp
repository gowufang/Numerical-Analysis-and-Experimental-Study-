#include <stdio.h>
#include <stdlib.h> 
#define N 10 //�����С��Χ
/** ʹ���Ѿ������x����ǰ����x����getx()���ã�* float a[][]    ϵ������* float x[]        �������* int    i        ������* int    n        �����С* return        ��ʽ����Ҫ�ĺ�*/
float getm(float a[N][N], float x[N], int i, int n)
{float m = 0;
    int r;
    for(r=i+1; r<n; r++)
    {m += a[i][r] * x[r];
    }
    return m;
}
/** �ⷽ���飬����x* float a[][]    ϵ������* float b[]        �Ҷ���    * float x[]        �������* int    i        ������* int    n        �����С* return        ������ĵ�i����*/
float getx(float a[N][N], float b[N], float x[N], int i, int n)
{float result;
    if(i==n-1) //�������һ��x��ֵ
        result = float(b[n-1]/a[n-1][n-1]);
    else //��������xֵ�����ڹ�ʽ�е���Ͳ��֣���Ҫ����getm()������
        result = float((b[i]-getm(a,x,i,n))/a[i][i]);
    return result;
}
void main()
{
    //float a[N][N] = {{2,1,1},{1,3,2},{1,2,2}};
    //float b[N] = {4,6,5};
    float a[N][N];  //ϵ������
    float b[N]; //�Ҷ���
    float x[N]; //�������
    int i,j,k;
    int n=N; //�����С /*�û��ֹ��������*/
    printf("������ϵ������Ĵ�С��");
    scanf("%d", &n);
    printf("�������������ֵ��");
    for(i=0; i<n; i++)
    {for(j=0; j<n; j++)
        scanf("%f", &a[i][j]);
    }
    printf("�������Ҷ��");
    for(i=0; i<n; i++)
    {scanf("%f", &b[i]);
    }/*��ʾԭʼ����*/
    printf("\nԭʼ����\n");
    for(i=0; i<n; i++)
    {for(j=0; j<n; j++)
            printf("%f  ",a[i][j]);
        printf("\t|\t%f\n",b[i]);
    }printf("\n\n");/*���и�˹��ȥ*/
    for(j=0; j<n-1; j++)
    {for(i=j+1; i<n; i++)
        {float m = (float)(a[i][j]/a[j][j]);
            for(k=j; k<n; k++)
            {a[i][k] = a[i][k]-m*a[j][k];
            }
            b[i] = b[i]-m*b[j];
        }
} /*��ʾ��������*/
    printf("��˹��ȥ�����\n");
    for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
            printf("%f  ",a[i][j]);
        printf("\t|\t%f\n",b[i]);
}/*�ش���ʽ�ⷽ����*/
    for(i=n-1; i>=0; i--)
{x[i] = getx(a,b,x,i,n);
}/*��ʾ�������*/
    printf("\n\n�������\n");
    for(i=0; i<n; i++)
{
printf("x%d = %f\n", i+1,x[i]);
    }
}
