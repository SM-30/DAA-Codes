#include<stdio.h>
#include<conio.h>
void sort(double [], double[], double[]);
void knapsack(double[], double[]);
int n,i,j,m,c=0;
double temp,mprofit=0.0;
int main()
{
    printf("Enter range:\n");
    scanf("%d",&n);
    printf("Enter the maximum capaciy:\n");
    scanf("%d",&m);
    double p[n],w[n];
    double x[n],y[n];
    printf("Enter the profits:\n");
    for(i=0; i<n; i++)
    scanf("%lf",&p[i]);
    printf("Enter the weights:\n");
    for(i=0; i<n; i++)
    scanf("%lf",&w[i]);
    for(i=0; i<n; i++)
    y[i] = p[i] / w[i];
    sort(p,w,y);
    knapsack(x,w);
    printf("The final distribution:\n");
    for(i=0; i<n; i++)
    printf("%.3lf part of %.3lf\n",x[i],w[i]);
    for(i=0; i<n; i++)
    mprofit += x[i] * p[i];
    printf("\nMaximum profit: %.3lf",mprofit);
}
void sort(double a[], double b[], double c[])
{
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(c[j] < c[j+1])
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }
}
void knapsack(double a[], double b[])
{
    for(i=0; i<n; i++)
    a[i] = 0.0;
    int u = m;
    for(i=0; i<n; i++)
    {
        if(b[i] > u)
        break;
        a[i] = 1.0;
        u = u - b[i];
        c++;
    }
    if(c <= m)
    a[c] = u / b[c];
}
