#include<stdio.h>
#include<alloc.h>
#include<conio.h>

typedef struct listnode* listpointer;

struct listnode
{
	int data;
	listpointer next;
};

listpointer first=NULL,node;

void create();
void list();
void sort();

void main()
{
	int choice;
	do
	{
		clrscr();
		printf("\n\tLINKED LIST OPERATIONS\n");
		printf("\n\t\t1. CREATE");
		printf("\n\t\t2. LIST");
		printf("\n\t\t3. SORT");
		printf("\n\t\t4. EXIT");
		printf("\n\n\tEnter your choice(1-4) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
			       break;
			case 2:list();
			       break;
			case 3:sort();
			       break;
			default:continue;
		}
		getch();
	}while(choice!=4);
}

void create()
{
	int i,n;
	if(first!=NULL)
	{
		printf("\nList already created...");
		return;
	}
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	if(n<1) return;
	printf("\nEnter %d elements into list :\n",n);
	first=(listpointer)malloc(sizeof(*first));
	scanf("%d",&first->data);
	node=first;
	for(i=0;i<n-1;i++)
	{
		node->next=(listpointer)malloc(sizeof(*node));
		node=node->next;
		scanf("%d",&node->data);
	}
	node->next=NULL;
	printf("\nList created with %d elements.",n);
}
void list()
{
	if(first==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	printf("\nElements in the list :\n\n");
	for(node=first;node!=NULL;node=node->next)
	printf(" %d",node->data);
}
void sort()
{
	int temp;
	listpointer node1,node2;
	if(first==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	for(node1=first;node1->next!=NULL;node1=node1->next)
	{
		node=node1;
		for(node2=node1->next;node2!=NULL;node2=node2->next)
			if(node2->data<node->data) node=node2;
		if(node==node1) continue;
		temp=node1->data;
		node1->data=node->data;
		node->data=temp;
	}
	printf("\nList is sorted...");
}
