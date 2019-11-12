#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node *list;
list insertF(list h,int data)
{
	list p=(list)malloc(sizeof(struct node));
	p->data=data;
	p->next=NULL;
	p->prev=NULL;
	if(h==NULL)
	{h=p;}
	else
	{p->next=h;
	 h->prev=p;h=p;
	}return h;
}

list insertE(list h,int data)
{
	list p=(list)malloc(sizeof(struct node));
	p->data=data;
	p->next=NULL;
	p->prev=NULL;
	list t=h;
	if(h==NULL)
	{h=p;}
	
	else
	{
	 while(t->next!=NULL)
	{t=t->next;
	}
	t->next=p;
	 p->prev=t;
	}return h;
}

list deleteE(list h)
{
	list t=h;
	h=h->next;
	free(t);
	return h;
}

list deleteF(list h)
{
	list t=h;
	list d;
	while(t->next->next!=NULL)t=t->next;
	
	free(t->next);t->next=NULL;
	return h;
}

void display(list h)
{
	list t=h;
	while(t!=NULL)
	{printf("%d\n",t->data);t=t->next;
	}
}

int main()
{
int op=0;int x;
list h=NULL;
	do
	{
	printf("1.Enter end\n");
	printf("2.enter front\n");
	printf("3.delete end\n");
	printf("4.delete front\n");
	printf("5.display\n");
	printf("6.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:printf("Enter ");scanf("%d",&x);h=insertE(h,x);break;
		case 2:printf("Enter ");scanf("%d",&x);h=insertF(h,x);break;
		case 3:h=deleteE(h);break;
		case 4:h=deleteF(h);break;
		case 5:display(h);break;
		case 6:printf("End");
	}
	}while(op!=6);

}


