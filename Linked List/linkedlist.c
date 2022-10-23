#include<stdio.h>
#include<stdlib.h>
int x,y;
int item,key;
struct node
{
    int data;
    struct node *link;
};
struct node *head;
void insbeg()
{
    printf("\nEnter the element to be inserted at beginning:\n");
    scanf("%d",&x);
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=head;
    head=new;
    new->data=x;
}
void insend()
{
    printf("\nEnter the element to be inserted at end:\n");
    scanf("%d",&x);
    struct node *new,*ptr;
    new=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr->link!=0)
    {
        ptr=ptr->link;
    }
    ptr->link=new;
    new->data=x;
    new->link=0;
}
void insbet()
{
    int pos,i=1;
    int count=0;
    struct node *new,*ptr,*temp;
    printf("\nEnter the position to be inserted:\n");
    scanf("%d",&pos);
    ptr=head;
    while(ptr!=0)
    {
        count++;
        ptr=ptr->link;
    }
    if(pos>count)
     {
         printf("\nInvalid Position\n");
     }
    else 
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the element to be inserted:\n");
        scanf("%d",&x);
        temp=head;
        while(i<pos)
        {
            temp=temp->link;
            i++;
        }
        new->link=temp->link;
        temp->link=new;
        new->data=x;
    }
}
void delbeg()
{
    struct node *temp;
    if(head==0)
    {
        printf("\nList Empty\n");
    }
    else
    {
    temp=head;
    printf("\nDeleted element is %d\n",temp->data);
    head=head->link;
    free(temp);
    }
}
void delend()
{
    struct node *temp,*ptr;
    if(head==0)
    {
        printf("\nList Empty\n");
    }
    else
    {
        temp=head;
        while(temp->link!=0)
        {
            ptr=temp;
            temp=temp->link;
        }
        if(head==temp)
        {
            head=0;
            free(temp);
        }
        else
        {
            ptr->link=0;
            free(temp);
        }
    }
}
void delpos()
{
	 struct node *ptr,*temp;
	 ptr=head;
	 temp=ptr->link;
	 if(ptr->link==0)
	 	printf("\nList Empty\n");
	 else{
		 printf("\nEnter the element to be deleted:\n");
		 scanf("%d",&key);
    while(temp!=0){
     	if(temp->data!=key){
       ptr=temp;
       temp=temp->link;
     }
     else  
     {
       item=temp->data;
       ptr->link=temp->link;
       printf("%d is deleted",item);
       free(temp);
       break;
     }  
   }
 }  
 if(temp==0)
 printf("\nElement not found\n");
} 
void reverse()
{
    if(head==0)
    {
        printf("\nList Empty\n");
    }
    else
    {
    struct node *current,*next;
    struct node *prev=0;
    current=head;
    next=head;
    while(next!=0)
    {
        next=next->link;
        current->link=prev;
        prev=current;
        current=next;
    }
     head=prev;
     printf("\nList is reversed\n");
    }
}
void display()
{
   struct node *ptr;
    if(head==0)
    {
        printf("\nList Empty\n");
    }
    else
    {
   ptr=head;
   while(ptr!=0)
   {
      
       printf("\t%d",ptr->data);
        ptr=ptr->link;
   }
    }
}
int main()
{
    int ch,ch1;
    printf("\n------LINKED LIST OPERATIONS------\n");
    do
    {
        printf("\nChoose any Operation :\n   1)Insertion \n   2)Deletion \n   3)Reversal \n   4)Display\n   5)Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\n   Choose \n   1)Beginning \n   2)End \n   3)Between\n");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1 : insbeg();
                         break;
                case 2 : insend();
                         break;
                case 3 : insbet();
                         break;
                default : printf("\n------Wrong Choice------\n");         
            }
        }
        else if(ch==2)
        {
             printf("\n   Choose \n   1)Beginning \n   2)End \n   3)Between\n");
            scanf("%d",&ch1);
            switch(ch1)
              {
                case 1 : delbeg();
                         break;
                case 2 : delend();
                         break;
                case 3 : delpos();
                         break;
                default : printf("\n------Wrong Choice------\n");  
              }
         }
         else if(ch==3)
         {
             reverse();
         }
         else if(ch==4)
         {
             display();
         }
         else if(ch==5)
         {
             exit(0);
         }
         else
         {
             printf("\n------Wrong Choice------\n");
         }
    }while(ch!=5);
}
