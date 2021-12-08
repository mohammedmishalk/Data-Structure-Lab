#include<stdio.h>
#include<conio.h>

#define LENGTH 5

int queue[LENGTH];
int front=0,rear=0;

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
	if((rear+1)%LENGTH==front)
	{
		printf("\nSorry, queue is full...");
		return;
	}
	rear=(rear+1)%LENGTH;
	queue[rear]=x;
	printf("\n%d is added...",x);
}
void del()
{
	if(front==rear)
	{
		printf("\nSorry, queue is empty...");
		return;
	}
	front=(front+1)%LENGTH;
	printf("\n%d is removed...",queue[front]);
}
void list()
{
	int i;
	if(front==rear)
	{
		printf("\nSorry, queue is empty...");
		return;
	}
	printf("\nThe queue :\n\n");
	i=front;
	do
	{
		i=(i+1)%LENGTH;
		printf("%d\t",queue[i]);
	}
	while(i!=rear);
}

