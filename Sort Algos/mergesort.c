#include <stdio.h>
#include <stdlib.h>
int arr[100];
int len;
int sortedarr[100];
void mergesort(int low,int high);
void merge(int low, int mid, int high);

int main()
{
   printf("enter the length of the array\n");
   scanf("%d",&len);
   printf("enter the array");
    for(int i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }

    mergesort(0,len-1);
    printf("the sorted array is:");
    for(int i=0;i<len;i++)
    {
        printf("%d\n",arr[i]);
    }
}

void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

void merge(int low, int mid, int high)
{
 int i,f,s;
 i=low;
 f=low;
 s=mid+1;
 int b[100];
 while(f<=mid && s<=high)
 {
     if(arr[f]<=arr[s])
     {
         b[i]=arr[f];
         i++;
         f++;
     }
     else if(arr[s]<=arr[f])
     {
         b[i] = arr[s];
         i++;
         s++;
     }
 }
 if(f>mid)
 {
     for(int j=s;j<=high;j++)
     {
         b[i]=arr[j];
         i++;
     }
 }
 else
 {
     for(int j=f;j<=mid;j++)
     {
         b[i]=arr[j];
         i++;
     }
 }

 for(int j=low;j<=high;j++)
 {
     arr[j]=b[j];
 }
}
