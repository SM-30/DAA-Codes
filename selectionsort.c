#include<stdio.h>
#include<conio.h>
int main()
{
    int size,i,j,min,temp;
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    int a[size];
    printf("Enter the array:\n");
    for(i=0;i<size;i++)
    scanf("%d" ,&a[i]);
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("-----------------------\n");
    printf("The Sorted Array:\n");
    for(i=0;i<size;i++)
    printf("%d ",a[i]);
    return 0;
}