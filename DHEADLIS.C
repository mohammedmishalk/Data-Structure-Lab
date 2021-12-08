#include<stdio.h>
#include<alloc.h>
#include<conio.h>

typedef struct listnode* listpointer;

struct listnode
{
	int data;
	listpointer next,prev;
};

listpointer head,node,p;
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
	listpointer head=(listpointer)malloc(sizeof(*head));
	head->next=head->prev=head;
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
	if(head->next!=head)
	{
		printf("\nList already created...");
		return;
	}
	printf("\nEnter the number of elements : ");
	scanf("%d",&listSize);
	if(listSize<1) return;
	printf("\nEnter %d elements into list :\n",listSize);
	node=head;
	for(i=0;i<listSize;i++)
	{
		node->next=(listpointer)malloc(sizeof(*node));
		node->next->prev=node;
		node=node->next;
		scanf("%d",&node->data);
	}
	node->next=head;
	head->prev=node;
	printf("\nList created with %d elements.",listSize);
}
void list()
{
	if(head->next==head)
	{
		printf("\nList is empty...");
		return;
	}
	printf("\nElements in the list :\n\n");
	for(node=head->next;node!=head;node=node->next)
	printf(" %d",node->data);
}
void insert(int x,int loc)
{
	int i;
	if(loc<1 || loc>listSize+1)
	{
		printf("\nInvalid location...");
		return;
	}
	node=(listpointer)malloc(sizeof(*node));
	node->data=x;
	p=head;
	if(loc<=listSize/2)
	for(i=0;i!=loc-1;i++,p=p->next)
	;
	else
	for(i=listSize+1;i!=loc-1;i--,p=p->prev)
	;
	node->next=p->next;
	node->prev=p;
	p->next=node;
	node->next->prev=node;
	listSize++;
	printf("\nOne element inserted...");
}
void delv(int x)
{
	if(head->next==head)
	{
		printf("\nList is empty...");
		return;
	}
	for(node=head->next;node!=head && node->data!=x;node=node->next)
	;
	if(node==head)
	{
		printf("\nElement not found...");
		return;
	}
	node->prev->next=node->next;
	node->next->prev=node->prev;
	free(node);
	listSize--;
	printf("\nOne element deleted...");
}
void delp(int loc)
{
	int i;
	if(head->next==head)
	{
		printf("\nList is empty...");
		return;
	}
	if(loc<1 || loc>listSize)
	{
		printf("\nInvalid location...");
		return;
	}
	if(loc<=listSize/2)
	for(i=1,node=head->next;i!=loc;i++,node=node->next)
	;
	else
	for(i=listSize,node=head->prev;i!=loc;i--,node=node->prev)
	;
	node->prev->next=node->next;
	node->next->prev=node->prev;
	free(node);
	listSize--;
	printf("\nOne element deleted...");
}
