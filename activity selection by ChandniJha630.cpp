//activity selection problem 
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cout<<"Enter Total number of activities: ";
	cin>>n;
	int s[2][n],sc[3][n];
	for(int i=0;i<n;i++){
		cout<<"Enter start and finish time of a"<<i<<": ";
		cin>>s[0][i]>>s[1][i];	
	}
	for(int i=0;i<n;i++){
		sc[0][i]=s[0][i];
		sc[1][i]=s[1][i];
		sc[2][i]=i;
	}
	cout<<endl;
	cout<<endl;
	sort(sc[1],sc[1]+n);
	for(int i=0;i<n;i++){
		cout<<"start and finish time of a"<<i<<": ";
		cout<<sc[0][i]<<" "<<sc[1][i]<<endl;	
	}
	
	int count=1,et=sc[1][0];
	cout<<"activity a"<<sc[2][0]<<" is selected with start time"<<sc[0][0]<<" and endtime "<<sc[1][0]<<" is selected"<<endl;
	for(int i=1;i<n;i++){
		if(sc[0][i]>=et && sc[1][i]>et){
			cout<<"activity a"<<sc[2][i]<<" is selected with start time"<<sc[0][i]<<" and endtime "<<sc[1][i]<<" is selected"<<endl;
			et=sc[1][i];
			count++;
		}
	}
	cout<<"Total selected activity= "<<count<<endl;
	cout<<endl;
	return 0;
}
