#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char opStack[50];
char infix[50];
char postfix[50];

int i,j,top=0;

void pop();
void push(char);
int lessPriority(char,char);

void main()
{
 	char ch;
	printf("enter infix expression");
	scanf("%s",infix);
	while((ch=infix[i++])!='\0')
	{
		switch(ch)
		{
			case ' ': break;
			case '(':
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '%':
				push(ch);
				break;
			case ')':
				pop();
				break;
			default:
				postfix[j] = ch;
				j++;
		}
	}
	while(top>=0)
	{
		postfix[j]=opStack[--top];
		j++;
	}
	postfix[--j]='\0'; //deleting closing braces
	printf("\n Infix expression:%s",infix);
	printf("\n Postfix expression:%s",postfix);
}
int lessPriority(char op,char op_at_stack)
{
	int k;
	int pv1;
	int pv2;

	char operator[] = { '+','-','*','/','%','^','(' };
	int priority_value[] = {0,0,1,1,2,3,4};

	if(op_at_stack == '(')
	return 0;
	
	for(k=0;k<6;k++)
	{
		if(op==operator[k])
			pv1=priority_value[k];
	}
	for(k=0;k<6;k++)
	{
		if(op_at_stack==operator[k])
			pv2=priority_value[k];
	}
	if(pv1<pv2)
		return 1;
	else
		return 0;
}

void push(char op)
{
	if(top==0)
	{
		opStack[top]=op;
		top++;
	}
	else
	{
		if(op!='(')
		{
			while(lessPriority(op,opStack[top-1]==1 && top>0))
			{
				postfix[j] = opStack[--top];
				j++;
			}
			opStack[top] = op;
			top++;
		}
	}
}
void pop()
{
	while(opStack[--top]!='(')
	{
		postfix[j] = opStack[top];
		j++;
	} //transferring opStack to postfix expression
}
	
	
