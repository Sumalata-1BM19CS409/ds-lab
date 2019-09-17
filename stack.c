#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int top=-1,stack[MAX];
void push();
void pop();
void display();

void main()
{
	int ch;
	printf("\n STACK MENU");
	printf("\n 1.push \t 2.pop \t 3.display \t 4.exit");
	while(ch!=4)
	{
	printf("\n enter your choice(1-4)");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: push();
		break;
	case 2: pop();
		break;
	case 3: display();
		break;	
	case 4: exit(0);
	default:printf("\n INVALID CHOICE");
	}
	}

}
void push()
{
	int val;
	if(top==MAX-1)
	printf("\n ERROR: STACK OVERFLOW");
	else
	{
	printf("\n ENTER THE ELEMENT TO PUSH:");
	scanf("%d", &val);
	top=top+1;
	stack[top]=val;
	}
}

void pop()
{
	if(top==-1)
	printf("\n ERROR:STACK UNDERFLOW");
	else
	{
	printf("\n the popped out element is %d", stack[top]);
	top=top-1;
}
}

void display()
{	
	int i;
	if(top==-1)
	printf("ERROR: STACK IS EMPTY");
	else
	{
	printf("\n stack is \n");
	for(i=0;i<=top;i++)
	printf("%d\n", stack[i]);
	}
}
