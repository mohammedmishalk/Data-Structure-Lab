#include<stdio.h>
#include<conio.h>

#define LENGTH 5

int stack[LENGTH];
int top=0;

void push(int);
void pop();
void list();

void main()
{
	int ch,n;
	do
	{
		clrscr();
		printf("\n\tSTACK OPERATIONS\n");
		printf("\n\t\t1.PUSH");
		printf("\n\t\t2.POP");
		printf("\n\t\t3.LIST");
		printf("\n\t\t4.EXIT");
		printf("\n\n\tEnter your choice(1-4) : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element : ");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				list();
				break;
			default:continue;
		}
		getch();
	}while(ch!=4);
}

void push(int x)
{
	if(top==LENGTH)
	{
		printf("\nSorry, stack is full...");
		return;
	}
	stack[top++]=x;
	printf("\n%d is added...",x);
}
void pop()
{
	if(top==0)
	{
		printf("\nSorry, stack is empty...");
		return;
	}
	printf("\n%d is removed...",stack[--top]);
}
void list()
{
	int i;
	if(top==0)
	{
		printf("\nSorry, stack is empty...");
		return;
	}
	printf("\nThe stack :\n");
	for(i=top-1;i>=0;i--)
		printf("\n%d",stack[i]);
}

