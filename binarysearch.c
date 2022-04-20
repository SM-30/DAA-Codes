#include<stdio.h>
#include<conio.h>
int main()
{
    double time_spent = 0.0;
    int size,i,k,lb,ub,mid,x=0;
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    int a[size];
    printf("Enter the sorted array:\n");
    for(i=0;i<size;i++)
    scanf("%d",&a[i]);
    printf("Enter the value to search:\n");
    scanf("%d",&k);
    lb=0,ub=size-1;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(k>a[mid])
        lb=mid+1;
        else if(k<a[mid])
        ub=mid-1;
        else if(k==a[mid])
        {
            printf("--------------------------------\n");
            printf("Element found at %d position",mid+1);
            x=1;
            break;
        }  
    }
    if(x==0)
    {
        printf("----------------------\n");
        printf("Number not found");
    }
    return 0;
}