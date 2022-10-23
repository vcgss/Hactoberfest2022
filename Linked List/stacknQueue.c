#include<stdio.h>
#include<stdlib.h>
int x, y;
struct node{
	int data;
	struct node *link;
	};
struct node *top = 0;
struct node *front = 0;
struct node *rear = 0;

void push(){
	printf ("\nEnter the element to be inserted in stack\n");
	scanf ("%d", &x);
    struct node *new;
    new = (struct node *) malloc (sizeof (struct node));
    new->link = top;
    top = new;
    new->data = x;
	}

void display(){
	struct node *temp;
    temp = top;
    if (top == 0)
	printf ("\nStack is empty\n");
	else{
		while (temp != NULL){
			printf ("\t%d", temp->data);
			temp = temp->link;
			}
		}
	}

void pop (){
	struct node *temp;
	temp = top;
	if(top == 0){
		printf ("\nStack is empty\n");
		}
  	else{
		  printf ("\nElement popped is %d\n", temp->data);
		  top = temp->link;
		  free (temp);
		  }
	}

void enqueue(){
	printf ("\nEnter the value to be inserted\n");
    scanf ("%d", &y);
    struct node *newnode;
    newnode = (struct node *) malloc (sizeof (struct node));
    newnode->data = y;
    newnode->link = 0;
	if (front == 0 && rear == 0){
		front = newnode;
        rear = newnode;
		}
    else{
		rear->link = newnode;
        rear = newnode;
		}
	}

void display1(){
	struct node *ptr;
	if (front == 0 && rear == 0){
		printf ("\nQueue empty\n");
		}
	else{
		ptr = front;
		while (ptr != 0){
			printf ("\t%d", ptr->data);
			ptr = ptr->link;
			}
		}
	}

void dequeue(){
	struct node *ptr;
	ptr = front;
	if(front == NULL && rear == NULL){
		printf ("\nQueue is empty\n");
		}
    else if(front==rear){
        printf("\nDequeued element is %d\n",front->data);
        front=0;
        rear=0;
		}
    else{
		printf ("Dequeued element is %d\n", front->data);
		front = front->link;
		free (ptr);
		}
	}

void main(){
  int ch, ch1;
  do
    {
      printf ("\nChoose any one :\n 1)Stack\n 2)Queue\n 3)Exit\n");
      scanf ("%d", &ch1);
      if (ch1 == 1)
	{
	  printf ("\nStack Operations\n");
	  do
	    {
	      printf ("\nChoose:\n1.push \n2.pop \n3.display \n4.exit\n");
	      scanf ("%d", &ch);
	      switch (ch)
		{
		case 1:
		  push ();
		  break;
		case 2:
		  pop ();
		  break;
		case 3:
		  display ();
		  break;
		case 4:
		  break;

		default:
		  printf ("\nWrong choice\n");
		}

	    }
	  while (ch != 4);
	}
      else if (ch1 == 2)
	{
	  printf ("\nQueue Operations\n");
	  do
	    {
	      printf
		("\nChoose:\n1.Enqueue \n2.Dequeue \n3.display \n4.exit\n");
	      scanf ("%d", &ch);
	      switch (ch)
		{
		case 1:
		  enqueue ();
		  break;
		case 2:
		  dequeue ();
		  break;
		case 3:
		  display1 ();
		  break;
		case 4:
		  break;

		default:
		  printf ("\nWrong choice\n");
		}
	    }
	  while (ch != 4);
	}
      else if (ch1 == 3)
	{
	  exit (0);
	}
      else
	{
	  printf ("\nWRONG CHOICE\n");
	}
    }
  while (ch != 3);
}
