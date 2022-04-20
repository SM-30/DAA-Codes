#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j,m,c=0,x;
    printf("Enter the range of array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the number to search:\n");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        if(a[i]==m)
        {
            c=1;
            x=i+1;
            break;
        }
    }
    printf("---------------------------\n");
    if(c==1)
    printf("Number found at position: %d",x);
    else
    printf("Number not found");
    return 0;
}