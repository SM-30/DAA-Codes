
#include<stdio.h>
#include<conio.h>
#define INT_MIN -99999
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int rodCutting(int n, int value[])
{
    int i,j;
    int result[n+1];
    result[0]=0;
    for(i=1;i<=n;i++)
    {
        result[i]=INT_MIN;
        for(j=0;j<i;j++)
        {
            result[i]=max(result[i],value[j]+result[i-(j+1)]);
        }
    }
    return result[n];
}
int main()
{
    int n;
    printf("Enter the length of the rod: ");
    scanf("%d", &n);
    int value[n];
    printf("Enter the values of pieces of rod of all size:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&value[i]);
    printf("Maximum obtainable value by cutting up the rod in many pieces are:\n");
    printf("%d ",rodCutting(n,value));
    printf("\n");
    return 0;
}