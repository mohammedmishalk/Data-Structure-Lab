#include<stdio.h>
#include<alloc.h>
#include<conio.h>

typedef struct listnode* listpointer;

struct listnode
{
	int data;
	listpointer next;
};

listpointer fnode=NULL,p;
int listSize=0;

void create();
void list();
void insert(int,int);
void delv(int);
void delp(int);

void main()
{
	int choice;
	int n,pos;
	do
	{
		clrscr();
		printf("\n\tLINKED LIST OPERATIONS\n");
		printf("\n\t\t1. CREATE");
		printf("\n\t\t2. LIST");
		printf("\n\t\t3. INSERT");
		printf("\n\t\t4. DELETE BY VALUE");
		printf("\n\t\t5. DELETE BY POSITION");
		printf("\n\t\t6. EXIT");
		printf("\n\n\tEnter your choice(1-6) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
			       break;
			case 2:list();
			       break;
			case 3:printf("\nEnter the data : ");
			       scanf("%d",&n);
			       printf("Enter the position(1-%d) : ",listSize+1);
			       scanf("%d",&pos);
			       insert(n,pos);
			       break;
			case 4:printf("\nEnter the data : ");
			       scanf("%d",&n);
			       delv(n);
			       break;
			case 5:printf("\nEnter the position(1-%d) : ",listSize);
			       scanf("%d",&pos);
			       delp(pos);
			       break;
			default:continue;
		}
		getch();
	}while(choice!=6);
}

void create()
{
	int i;
	if(fnode!=NULL)
	{
		printf("\nList already created...");
		return;
	}
	printf("\nEnter the number of elements : ");
	scanf("%d",&listSize);
	if(listSize<1) return;
	printf("\nEnter %d elements into list :\n",listSize);
	fnode=(listpointer)malloc(sizeof(*fnode));
	scanf("%d",&fnode->data);
	fnode->next=NULL;
	p=fnode;
	for(i=0;i<listSize-1;i++)
	{
		p->next=(listpointer)malloc(sizeof(*p));
		p=p->next;
		scanf("%d",&p->data);
	}
	p->next=NULL;
	printf("\nList created and %d elements inserted into the list",listSize);
}
void list()
{
	if(fnode==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	printf("\nElements in the list :\n\n");
	for(p=fnode;p!=NULL;p=p->next)
	printf(" %d",p->data);
}
void insert(int x,int loc)
{
	int i;
	listpointer node;
	if(loc<1 || loc>listSize+1)
	{
		printf("\nInvalid location...");
		return;
	}
	node=(listpointer)malloc(sizeof(*node));
	node->data=x;
	if(loc==1)
	{
		node->next=fnode;
		fnode=node;
	}
	else
	{
		for(i=1,p=fnode;i!=loc-1;i++,p=p->next)
		;
		node->next=p->next;
		p->next=node;
	}
	listSize++;
	printf("\nOne element inserted...");
}
void delv(int x)
{
	listpointer d;
	if(fnode==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	if(fnode->data==x)
	{
		d=fnode;
		fnode=fnode->next;
	}
	else
	{
		for(p=fnode;p->next!=NULL && p->next->data!=x;p=p->next)
		;
		if(p->next==NULL)
		{
			printf("\nElement not found...");
			return;
		}
		d=p->next;
		p->next=d->next;
	}
	free(d);
	listSize--;
	printf("\nOne element deleted...");
}
void delp(int loc)
{
	int i;
	listpointer d;
	if(fnode==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	if(loc<1 || loc>listSize)
	{
		printf("\nInvalid location...");
		return;
	}
	if(loc==1)
	{
		d=fnode;
		fnode=fnode->next;
	}
	else
	{
		for(i=1,p=fnode;i!=loc-1;i++,p=p->next)
		;
		d=p->next;
		p->next=d->next;
	}
	free(d);
	listSize--;
	printf("\nOne element deleted...");
}
