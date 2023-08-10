#include<stdio.h>
#include<stdlib.h>
struct node 
{
   int data;
   struct node * next;
};
struct node * insertatbegin(struct node *head ,int data)
{
  struct node * a = (struct node *)malloc(sizeof(struct node ));
  a->next = head;
  a->data = data;
  return a;
}
struct node * insertinbetween (struct node *head, int data, int k)
{
 struct node * b = (struct node *)malloc(sizeof(struct node ));
 struct node *ptr = head;
 int i = 0;
 while (i!=k)
  {
     ptr=ptr->next;
     i++;
   }
 b->next = ptr->next;
 ptr->next = b;
 b->data=data;
 return head;    
}
struct node * insertatend(struct node *head, int data)
{
  struct node * c = (struct node *)malloc(sizeof(struct node ));
  c->data = data;
  struct node *ptr = head;
  while(ptr->next!= NULL)
  {
    ptr = ptr->next;
  }
  c->next=NULL;
  ptr->next = c;
  return head;
}
struct node * insertafteranode(struct node * head,struct node * prevnode,int data)
{
    struct node * d = (struct node *)malloc(sizeof(struct node ));
    d->data = data;
    d->next = prevnode->next;
    prevnode->next = d;
    return head;

}
void traverse(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
 
}
struct node * deleteatbegin(struct node * head)
{
  struct node *u = head;
  head = head->next;
  free(u);
  return head;
}
struct node * deleteinbetween(struct node * head,int index)
{
  int i=0;
  struct node *u = head;
  struct node *p = head->next;
  while (i!=index-1)
  {
    u=u->next;
    p=p->next;
  }
  u->next = p->next;
  free(p);
  return head;
}
struct node * deleteatend(struct node * head)
{
 struct node *u = head;
 struct node *p = head->next;
 while(p->next!=NULL)
 {
   u=u->next;
   p=p->next;
 }
 u->next=NULL;
 free(p);
 return head;
}
struct node * deleteforagivenvslue(struct node * head,int value)
{
  struct node *u = head;
  struct node *p = head->next;
  while(p->data!=value && p->next!=NULL)
  {
    u=u->next;
    p=p->next;
    }
  if (p->data==value)
  {
    u->next = p->next;
    free(p);
  }
  return head;
}

void main()
{
  int d, between,c2,c1,c3,val,b;
  char prev [10];
  struct node * head ;
  struct node * second;
  head = (struct node *)malloc(sizeof(struct node ));
  second = (struct node *)malloc(sizeof(struct node )); 
  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = NULL;
  printf("the linked list is :");
  traverse(head);
  printf("Enter 1 to perform insertion and 2 to perform deletion.");
  scanf("%d",&c1);
  switch(c1)
  {
    case 1:
   {
    printf("Enter to perform insertion at following stage also enter the data:\n ");
    printf("enter 1 for insert at beginning:\n");
    printf("Enter 2 for insert in between:\n");
    printf("Enter 3 for inserting at end\n");
    printf("Enter 4 for insert after a node\n");
    scanf("%d",&c2);
   switch(c2)
   {
    case 1:
    {
      printf("Enter the data:\n");
      scanf("%d",&d);
      head =  insertatbegin(head , d);
      traverse(head);
      break;
    }
    case 2:
    {
      printf("Enter the data:\n");
      scanf("%d",&d);
      printf("enter the node after which you want to add the data:\n");
      scanf("%d,&between");
      head = insertinbetween(head,d,between);
      traverse(head);
      break;
    }
    case 3:
    {
      printf("Enter the data:\n");
      scanf("%d",&d);
      head = insertatend(head, d);
      traverse(head);
      break;
    }
    case 4: 
    {
     printf("Enter the data:\n");
      scanf("%d",&d);
      head = insertafteranode(head, second,d);
      traverse(head);
      break;
    }
    default :
    printf("Enter a valid choice");
   } 
   break;
    }
  case 2:
   {
   printf("Enter to perform deletion at following stage also enter the data:\n ");
   printf("Enter 1 for deletion at beginning:\n");
   printf("Enter 2 for deletion in between:\n");
   printf("Enter 3 for deletion at end\n");
   printf("Enter 4 for deletion after a node\n");
   scanf("%d",&c3);
    switch(c3)
   {
    case 1:
    {
     printf("The linked list after deletion.\n");
     deleteatbegin(head);
     traverse(head);
     break;
    }
    case 2:
    {
     printf("The node you want to delete\n");
     scanf("%d",&b);
     printf("The linked list after deletion.\n");
     deleteinbetween(head,b);
     traverse(head);
     break;
    }
    case 3:
    {
     printf("The linked list after deletion.\n");
     deleteatend(head);
     traverse(head);
     break;
    }
    case 4:
    {
     printf("Enter the value you want to delete:\n");
     scanf("%d",&val);
     deleteforagivenvslue(head,val);
     printf("The linked list after deletion.");
     traverse(head);
     break;
    }
    default:
    {
     printf("Enter a valid choice\n");
      break;
     }
  break;
   }   
  default:
  {
  printf("Enter a valid choice\n");
  break;
  }
  }
  }
}

