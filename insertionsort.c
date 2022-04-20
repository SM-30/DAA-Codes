#include<stdio.h>
#include<conio.h>
int main()
{
    int size,i,j,temp;
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    int a[size+1];
    a[0]= -32768;
    printf("Enter the array:\n");
    for(i=1;i<=size;i++)
    scanf("%d",&a[i]);
    for(i=2;i<=size;i++)
    {
        j=i;
        while(a[j]<a[j-1])
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }  
    }
    printf("------------------------\n");
    printf("The Sorted array:\n");
    for(i=1;i<=size;i++)
    printf("%d ",a[i]);
    return 0;
}