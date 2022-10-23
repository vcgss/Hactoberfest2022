#include<stdio.h>
int main()
{
    int a[50],n,i,j,t;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the arrays element\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }
    printf("The sorting is \n");
    for(i=0;i<n;i++)
    printf(" %d\n", a[i]);
    return 0;
}