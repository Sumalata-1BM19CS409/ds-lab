#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE createnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("No memory allocation!\n");
		exit(0);
	}
}
NODE insert_front(NODE head,int item)
{
	NODE p;
	p=createnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("Error: Empty list!\n");
		exit(0);
	}
	p=head;
	printf("Elements in the list are\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
NODE insert_end(NODE head,int item)
{
	NODE p,q;
	q=createnode();
	q->data=item;
	q->next=NULL;
	
	if(head==NULL)
		{
			
			return q;
		}
	p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=q;
	return head;
}
NODE insert_pos(NODE head,int item,int pos)
{
	NODE curr,prev=NULL,newn;
	int count=1;
	newn=createnode();
	newn->data=item;
	newn->next=NULL;
	if(head==NULL)
	{
		if(pos==1)
			return newn;
		else
		{
			printf("Error: Invalid position!\n");
			return 0;
		}
	}
	if(pos==1)
	{
		newn->next=head;
		head=newn;
		return head;
	}
	else
	{
		curr=head;
		while(curr!=NULL&&count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(count==pos)
		{
			prev->next=newn;
			newn->next=curr;
			return head;
		}
		else
		{
			printf("Error: Invalid position!\n");
			return head;
		}
	}
}
int main()
{
	NODE head=NULL;
	int c,e,p,v;
	
	while(1)
	{
	   printf("******LINKED LIST MENU******\n1.Insert front\t2.Insert end\t3.Insert at specific position\t4.Display\t5.Exit");
		printf("\nEnter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter element to be inserted\n");
				scanf("%d",&e);
				head=insert_front(head,e);
				break;
			case 2: printf("Enter element to be inserted\n");
				scanf("%d",&e);
				head=insert_end(head,e);
				break;
			case 3:printf("Enter position and value\n");
				scanf("%d%d",&p,&v);
				head=insert_pos(head,v,p);
				break;
			case 4: display(head);
				break;
			case 5:
				exit(0);
			default: printf("\n Invalid choice!");
				
		}
	}
	return 0;
}