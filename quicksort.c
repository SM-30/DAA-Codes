#include<stdio.h>
#include<conio.h>
void sort(int,int,int arr[]);
int divnrule(int,int,int arr[]);
int l,h,size,p,t,i,j;
int main()
{
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    int a[size+1];
    printf("Enter the array:\n");
    for(i=0;i<size;i++)
    scanf("%d",&a[i]);
    a[size]=32767;
    l=0,h=size;
    sort(l,h,a);
    printf("------------------------------------\n");
    printf("The final sorted array is:\n");
    for(j=0;j<size;j++)
    printf("%d ",a[j]);
    return 0;
}
void sort(int l,int h,int arr[])
{
    int x;
    if(l<h)
    {
        x=divnrule(l,h,arr);
        sort(l,x,arr);
        sort(x+1,h,arr);
    }
}
int divnrule(int l,int h,int arr[])
{
    p=arr[l];
    i=l,j=h;
    while(i<j)
    {
        while(arr[i]<=p)
        i++;
        while(arr[j]>p)
        j--;
        if(i<j)
        {
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    t=arr[l];
    arr[l]=arr[j];
    arr[j]=t;
    return j;
}