#include <stdio.h>
int n;
char ans='y';
void linearSearch(int arr[],int size,int key){
	int flag=-1;
	for(int i=0;i<size;i++){
		if(arr[i]==key){
		flag=i;
		break;
		}
	}
	if (flag==-1){
		printf("The element %d is not found",key);
	}
	else
		printf("\nThe element %d is found at %d",key,flag+1);
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
	printf("Select the method to search-\n1.Linear Search");
	scanf("%d",&opt);
	switch(opt){
	case 1:linearSearch(arr,size,key);break;
	default:printf("Invalid Option");
	}
	printf("\nSearch again?(y/n)");
	scanf("%s",&ans);
	}
}
