//fractional knapsack problem 

#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int obj,cons;
    cout<<"constraint wieght: ";
    cin>>cons;
    cout<<"Enter number of objects: ";
    cin>>obj;
   int prof[obj];
   int wg[obj];
   float ppw[obj];
   for(int i=0;i<obj;i++){
       cout<<"Profit: ";
       cin>>prof[i];
       cout<<"Wieght: ";
       cin>>wg[i];
       ppw[i]=float(prof[i])/float(wg[i]);
   }
   
   for(int i=0;i<obj;i++){
   	cout<<i+1<<" "<<prof[i]<<" "<<wg[i]<<" "<<ppw[i]<<endl;
   }
   int newcons=cons;
   float totalprofit=0;
   float copy[obj];
   float*ptr;
   for(int i=0;i<obj;i++){
       copy[i]=ppw[i];
   }
   cout<<"copied ppw before sort "<<endl;
   for(int i=0;i<obj;i++){
       cout<<copy[i]<<" ";
   }
   cout<<endl;
   ptr=copy+0;
   sort(copy,copy+obj,greater<int>());
     cout<<"copied ppw after sort "<<endl;
        for(int i=0;i<obj;i++){
       cout<<copy[i]<<" ";
   }
   cout<<endl;
  
   while(newcons!=0){
   	 int i=0;
       while(ppw[i]!=*ptr){
           i++;
   }
  
   ptr++;
   if(newcons<wg[i]){
   	wg[i]=newcons;
   }
   cout<<wg[i]<<"wieght picked up of object number"<<i<<"making profit "<<prof[i]<<endl;
   
   totalprofit+=wg[i]*ppw[i];
    newcons=newcons-wg[i];
   ppw[i]=0;//zero banaya taki ek hi cheez while loop shuru se shuru karne par count na ho
   }
   cout<<"Total Profit-> "<<totalprofit<<endl;
    return 0;
}

