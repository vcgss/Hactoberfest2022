
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

struct Node{
    float info;
    struct Node *link;
};

Node *sortedinsertion(Node *newnode,Node *sorted_list){
    if(sorted_list==NULL||sorted_list->info>=newnode->info){
        newnode->link=sorted_list;
        sorted_list=newnode;
    }else{
        Node *c=sorted_list;
        while(c->link!=NULL && c->link->info<newnode->info){
            c=c->link;
        }
        newnode->link=c->link;
        c->link=newnode;
    }
    return sorted_list;
}

Node *insertionsort(Node *head){
    Node *c=head,*sorted_list=NULL;
    while(c!=NULL){
        Node *next=c->link;
        sorted_list=sortedinsertion(c,sorted_list);
        c=next;
    }
    return sorted_list;
}
void printbucket(Node**B,int n){
int i; Node*p,*t;
for (i=0;i<n;i++){
    p=B[i];
    t=p;
    cout<<"B["<<i<<"]"<< "elements:";
    while(t!=NULL){
        cout<<t->info<<" ";
        t=t->link;
    }
    cout<<endl;
}
}
void Bucketsort(float *A,int n){
    Node *B[n-1];
    int j;
    for(int i=0;i<n;i++){
        B[i]=NULL;
    }
    for(int i=0;i<n;i++){
        j=floor(n*A[i]);
        Node *p=(Node *)malloc(sizeof(Node));
        p->info=A[i];
        p->link=B[j];
        B[j]=p;
    }
    for(int i=0;i<n;i++){
        B[i]=insertionsort(B[i]);
    }
    int i=0;
  // printbucket(B,n);
    while(i<n){
        for(int j=0;j<n;j++){
            if(B[j]==NULL){
                continue;
            }else{
                Node *p=B[j];
                while(p!=NULL){
                    A[i]=p->info;
                    i++;
                    p=p->link;
                }
            }
        }
    }
}


void Printarray(float *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}


int main(){
    int i,n;
    float A[20];
    cout<<"Enter the value of number of elements : ";
    cin>>n;
    printf("Enter the %d array elements\n",n);
    for(i=0;i<n;i++){
        printf("A[%d] = ",i);
        cin>>*(A+i);
    }
    Bucketsort(A,n);
    Printarray(A,n);
    return 0;
}




