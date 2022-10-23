#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int info;
    struct BST *LChild;
    struct BST *RChild;
}*root;
struct BST *new_node;
struct BST *S_Parent = NULL;
struct BST *PTR;
struct BST *Search_Parent(int );
struct BST *Search(int );
struct BST *Tree_Successor(struct BST * );
int value,ch,count=0;
//-------------Node Creation---------------------------------
struct BST *getNode()
{
 new_node=(struct BST *)malloc(sizeof(struct BST));
 if(!new_node)
 return NULL;
 else
 return new_node;
}
//-------------Creating Root in Tree---------------------------
struct BST *Create(int value)
{
    struct BST *ptr;
        ptr = getNode();
        ptr->info = value;
        ptr->LChild = NULL;
        ptr->RChild = NULL;
    return ptr;
}
//----------------Inserting values into Binary Tree--------------------------
 void Insert(int value)
{
   struct BST *Ptr, *Parent;
   Ptr= Search(value);
   if(Ptr!=NULL)
    {
     printf("Element already present\n");
 }
    else
      {
        Parent = Search_Parent(value);
        if(value > Parent->info)
          Parent->RChild=Create(value);
        else
          Parent->LChild=Create(value);
      }
}
//------------------Deletion----------------------------------
 void Delete()
{
  struct BST *Del_Node;
  struct BST *Child_Org_Del_Node;
  struct BST *Org_Del_Node;
  struct BST *Parent;
  int key;
  if(root == NULL)
  {
    printf("Tree is Empty\n");
  }
  else
  {
    printf("\nEnter the element to be deleted:");
  scanf("%d",&key);
  Del_Node= Search(key);
  if(Del_Node==NULL)
  {
   printf("\nThe Element is not present!! Enter another value..\n");
  }
  else
  {
    {
    if(Del_Node->LChild==NULL || Del_Node->RChild==NULL)
    Org_Del_Node=Del_Node;
    else
    Org_Del_Node = Tree_Successor(Del_Node);
  }
  {
      if(Org_Del_Node->LChild!=NULL)
      Child_Org_Del_Node = Org_Del_Node->LChild;
      else
      Child_Org_Del_Node = Org_Del_Node->RChild;
  }
  Parent = Search_Parent(Org_Del_Node->info);
  if(Parent==NULL)
    root=Child_Org_Del_Node;
    else
    {
     {
      if(Parent->LChild == Org_Del_Node)
      Parent->LChild = Child_Org_Del_Node;
      else
      Parent->RChild = Child_Org_Del_Node;
     }
      if(Org_Del_Node != Del_Node)
      {
        Del_Node->info = Org_Del_Node->info;
      }
      free(Org_Del_Node);
    }
    }
  }
}
//------------Tree Successor---------------------------
struct BST *Tree_Successor(struct BST *key)
{
    PTR=key->RChild;
    while(PTR->LChild!=NULL)
    {
        PTR=PTR->LChild;
    }
    return(PTR);
}
//------------------Display the tree ------------------------------
void Display(struct BST *InOrd)
{
    if(InOrd != NULL)
    {
        Display(InOrd->LChild);
        printf("\t%d", InOrd->info);
        Display(InOrd->RChild);
    }
}
//------------------Searching of element in Tree--------------------
struct BST *Search(int element)
{
   // struct BST *PTR;
    PTR=root;
    {
      while(PTR!=NULL && PTR->info!=element)
        {
         if(PTR->info > element)
         PTR=PTR->LChild;
         else
         PTR=PTR->RChild;
        }
    }
    return PTR;
 }
//------------------Searching Parent Node-------------------------------
struct BST *Search_Parent(int element)
{
    struct BST *PTR;
    PTR=root;
    //struct BST *S_Parent = NULL;
    while(PTR!=NULL&&PTR->info!=element)
    {
      S_Parent = PTR;
      if(S_Parent->info > element)
      PTR=PTR->LChild;
      else
      PTR=PTR->RChild;
    }
    return S_Parent;
}
//------------------Height of Tree------------------------------
int Height(struct BST *hgt)
{
  if(hgt==NULL)
  {
      return 0;
  }
  else
  {
    int LHeight, RHeight;
    LHeight = Height(hgt->LChild);
    RHeight = Height(hgt->RChild);
    if(LHeight > RHeight)
    return(LHeight+1);
    else
    return(RHeight+1);
  }
}
//-------------------------Main Function---------------------
int main()
{
    root=NULL;
    printf("\t********Binary Search Tree**********");
    while(1)
    {
        printf("\nAvailable Operations");
        printf("\n1.Insert\t2.Delete\t3.Display Tree\t4.Height\t5.Exit");
        printf("\nChoose the operation:");
        scanf("%d", &ch);
        switch(ch)
        {
          case 1:
            {
                if(count == 0)
                {
                printf("\nEnter the value of root node : ");
                scanf("%d", &value);
                root = Create(value);
                printf("\nEnter element to be inserted : ");
                scanf("%d", &value);
                Insert(value);
                count++;
                }
                else
                {
                    printf("\nEnter element to be inserted : ");
                    scanf("%d", &value);
                    Insert(value);
                }
            }
            break;
            case 2: Delete();
                    break;
            case 3:
            {
                struct BST *dis=root;
                if(dis==NULL)
                {
                    printf("The Tree is Empty\n");
                }
                else
                {
                  printf("\nThe In Order traversal of tree is : \n");
                  Display(dis);
                  printf("\n");
                }
            }
            break;
            case 4:
            {
              int height=Height(root);
              printf("\nThe Height of the tree is : %d\n",height);
            }
            break;
            case 5:
            {
                printf("\nSuccessfully Exited!!!!");
                exit(0);
            }
            default: printf("\nEnter Valid Input\n");
        }
    }
    return 0;
}
