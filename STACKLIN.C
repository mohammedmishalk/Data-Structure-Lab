#include<stdio.h>
#include<conio.h>
#include<alloc.h>

typedef struct stacknode* stackpointer;

struct stacknode
{
	int data;
	stackpointer next;
};

stackpointer top=NULL,node;

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
	node=(stackpointer)malloc(sizeof(*node));
	if(node==NULL)
	{
		printf("\nSorry, insufficient memory...");
		return;
	}
	node->data=x;
	node->next=top;
	top=node;
	printf("\n%d is added...",x);
}
void pop()
{
	if(top==NULL)
	{
		printf("\nSorry, stack is empty...");
		return;
	}
	printf("\n%d is removed...",top->data);
	node=top;
	top=top->next;
	free(node);
}
void list()
{
	if(top==NULL)
	{
		printf("\nSorry, stack is empty...");
		return;
	}
	printf("\nThe stack :\n");
	for(node=top;node!=NULL;node=node->next)
		printf("\n%d",node->data);
}
