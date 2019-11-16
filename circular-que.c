#include<stdio.h>
#include<stdlib.h>
#define MAX 4

void enqueue();
void dequeue();
void display();


int main()
{
 int r=-1,f=-1,q[20];
 int c;
 printf("\n Queue menu \n1.Enqueue 2.Dequeue 3.Display 4.Exit");
 while(c!=4)
 {
  printf("\n Enter choice: ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:enqueue(q,&r,&f);
    break;
   case 2:dequeue(q,&r,&f);
    break;
   case 3:display(q,&r,&f);
    break;
   case 4:exit(0);
  
   default:printf("\n Invalid choice \n");
  }
 }
 return 0;
}

void enqueue(int q[], int *r, int *f)
{
 int x;
 if((*f==0 && *r==MAX-1)||(*r+1==*f))
  printf("\n Queue Overflow");
 else
 {
  if(*r==-1)
  {
   *f=0;
   *r=0;
  }
  else if(*r==MAX-1)
   *r=0;
  else
   (*r)++;
  printf("\n Enter element to insert: ");
  scanf("%d",&x);
  q[*r]=x;
 }
}

void dequeue(int q[], int *r, int *f)
{
 if(*f==-1)
  printf("\n Queue Underflow");
 else
 {
  printf("\n Deleted element is %d",q[*f]);
  if(*f==*r)
  {
   *f=-1;
   *r=-1;
  }
  else if(*f==MAX-1)
   *f=0;
  else 
   (*f)++;
 }
}

void display(int q[], int *r, int *f)
{
 int i,j;
 if(*f==-1 && *r==-1)
  printf("\n Queue is Empty");
 else if(*f>*r)
 {
  for(i=*f;i<MAX;i++)
   printf("\t %d",q[i]);
  for(j=0; j<=*r;j++)
  printf("\t %d",q[j]);
 }
 else
 {
  for(i=*f;i<=*r;i++)
   printf("\n %d",q[i]);
 }
}
