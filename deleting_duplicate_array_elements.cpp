/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int deldup(int arr[],int n){
    int k;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]==arr[i]){
                 k=j;
                while(k!=n){
                arr[k]=arr[k+1];
                k++;
                }
                n=n-1;
            }
        }
    }
    return (arr,n);
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>*(arr+i);
    }
    cout<<"Array You Entered-> ";
    printArray(arr,n);
    (arr,n)=deldup(arr,n);
    cout<<"Array After Deleting Duplicate Elements-> ";
    printArray(arr,n);
    return 0;
}
