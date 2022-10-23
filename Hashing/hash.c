#include <stdio.h>
int isprime(int d)
{
  int flag=1;
  for(int i=2;i<d;i++)
  {
    if(d%i==0)
      flag=0;
  }
  return flag;
}
int main(void)
{
  int num,n,k[10],i;
  printf("Enter the number of elements to be entered in the hash table: ");
  scanf("%d",&n);
  for(int i=n;i;i++)
  {
    if(isprime(i)==1)
    {
      num=i;
      break;
    }
  }
  int Hash[num];
  printf("Size is %d\n",num);
  printf("Enter the elements to be entered into the Hash table : ");
  for(i=0;i<num;i++)
    Hash[i]=-1;
  for(i=0;i<num;i++){
    scanf("%d",&k[i]);
    int index=k[i]%num;
    if(Hash[index]==-1)
    {
      Hash[index]=k[i];
    }
    else{
      while(Hash[index]!=-1){
        index++;
        if(index==num)
          index=0;
      }
    Hash[index]=k[i];  
    }
  }
  for(i=0;i<num;i++){
    printf("Hash[%d]=%d\n",i,Hash[i]);
  }
}
/*
-----OUTPUT-----
Enter the number of elements to be entered in the hash table: 4
Size is 5
Enter the elements to be entered into the Hash table : 1
62
63
20
53
Hash[0]=20
Hash[1]=1
Hash[2]=62
Hash[3]=63
Hash[4]=53
*/
