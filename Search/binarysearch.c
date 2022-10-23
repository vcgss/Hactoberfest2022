#include <stdio.h>
int n;
char ans='y';
void binarySearch(int arr[],int size,int key){
	int temp,l,mid,h,flag=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}			
	l=0;
	h=size-1;
	while(l<=h){
		mid=(l+h)/2;
		if(arr[mid]==key){
			flag=1;
			break;
		}		
		if(arr[mid]<key){
		l=mid+1;
		}
		else if(arr[mid]>key){
		h=mid-1;
		}	
	}	
	if (flag==1){
		printf("The element %d is found",key);
	}
	else
		printf("\nThe element %d is not found",key);
}

void main(){
	int arr[100];
	int size,key,opt;
	printf("Enter the no of elements in an array: ");
	scanf("%d",&size);
	printf("Enter the elements of the array: ");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	while(ans=='y'||ans=='Y'){
	printf("Enter the element to search: ");
	scanf("%d",&key);
	printf("Select the method to search-\n1.Binary Search");
	scanf("%d",&opt);
	switch(opt){
	case 1:binarySearch(arr,size,key);break;
	default:printf("Invalid Option");
	}
	printf("\nSearch again?(y/n)");
	scanf("%s",&ans);
	}
}
