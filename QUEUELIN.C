#include<stdio.h>
#include<conio.h>
#include<alloc.h>

typedef struct queuenode* queuepointer;

struct queuenode
{
	int data;
	queuepointer next;
};

queuepointer front=NULL,rear=NULL,node;

void add(int);
void del();
void list();

void main()
{
	int ch,n;
	do
	{
		clrscr();
		printf("\n\tQUEUE OPERATIONS\n");
		printf("\n\t\t1.ADD");
		printf("\n\t\t2.DELETE");
		printf("\n\t\t3.LIST");
		printf("\n\t\t4.EXIT");
		printf("\n\n\tEnter your choice(1-4) : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element : ");
				scanf("%d",&n);
				add(n);
				break;
			case 2:
				del();
				break;
			case 3:
				list();
				break;
			default:continue;
		}
		getch();
	}while(ch!=4);
}

void add(int x)
{
	node=(queuepointer)malloc(sizeof(*node));
	if(node==NULL)
	{
		printf("\nSorry, insufficient memory...");
		return;
	}
	node->data=x;
	node->next=NULL;
	if(front==NULL) front=rear=node;
	else
	{
		rear->next=node;
		rear=rear->next;
	}
	printf("\n%d is added...",x);
}
void del()
{
	if(front==NULL)
	{
		printf("\nSorry, queue is empty...");
		return;
	}
	printf("\n%d is removed...",front->data);
	node=front;
	front=front->next;
	free(node);
}
void list()
{
	if(front==NULL)
	{
		printf("\nSorry, queue is empty...");
		return;
	}
	printf("\nThe queue :\n\n");
	for(node=front;node!=NULL;node=node->next)
		printf("%d\t",node->data);
}

