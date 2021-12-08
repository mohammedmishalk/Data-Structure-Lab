#include<stdio.h>
#include<alloc.h>
#include<conio.h>

typedef struct listnode* listpointer;

struct listnode
{
	int data;
	listpointer next;
};

listpointer head,node,p;
int listSize=0;

void create();
void list();
void sort();
void insert(int,int);
void delv(int);
void delp(int);

void main()
{
	int choice;
	int n,pos;
	head=(listpointer)malloc(sizeof(*head));
	head->next=NULL;
	do
	{
		clrscr();
		printf("\n\tLINKED LIST OPERATIONS\n");
		printf("\n\t\t1. CREATE");
		printf("\n\t\t2. LIST");
		printf("\n\t\t3. SORT");
		printf("\n\t\t4. INSERT");
		printf("\n\t\t5. DELETE BY VALUE");
		printf("\n\t\t6. DELETE BY POSITION");
		printf("\n\t\t7. EXIT");
		printf("\n\n\tEnter your choice(1-7) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
			       break;
			case 2:list();
			       break;
			case 3:sort();
			       break;
			case 4:printf("\nEnter the data : ");
			       scanf("%d",&n);
			       printf("Enter the position(1-%d) : ",listSize+1);
			       scanf("%d",&pos);
			       insert(n,pos);
			       break;
			case 5:printf("\nEnter the data : ");
			       scanf("%d",&n);
			       delv(n);
			       break;
			case 6:printf("\nEnter the position(1-%d) : ",listSize);
			       scanf("%d",&pos);
			       delp(pos);
			       break;
			default:continue;
		}
		getch();
	}while(choice!=7);
}

void create()
{
	int i;
	if(head->next!=NULL)
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
		node=node->next;
		scanf("%d",&node->data);
	}
	node->next=NULL;
	printf("\nList created with %d elements.",listSize);
}
void list()
{
	if(head->next==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	printf("\nElements in the list :\n\n");
	for(node=head->next;node!=NULL;node=node->next)
	printf(" %d",node->data);
}
void sort()
{
	int temp;
	listpointer node1;
	if(head->next==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	for(node1=head->next;node1->next!=NULL;node1=node1->next)
	{
		node=node1;
		for(p=node1->next;p!=NULL;p=p->next)
			if(p->data<node->data) node=p;
		if(node==node1) continue;
		temp=node1->data;
		node1->data=node->data;
		node->data=temp;
	}
	printf("\nList is sorted...");
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
	for(i=0,p=head;i!=loc-1;i++,p=p->next)
	;
	node->next=p->next;
	p->next=node;
	listSize++;
	printf("\nOne element inserted...");
}
void delv(int x)
{
	if(head->next==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	for(p=head;p->next!=NULL && p->next->data!=x;p=p->next)
	;
	if(p->next==NULL)
	{
		printf("\nElement not found...");
		return;
	}
	node=p->next;
	p->next=node->next;
	free(node);
	listSize--;
	printf("\nOne element deleted...");
}
void delp(int loc)
{
	int i;
	if(head->next==NULL)
	{
		printf("\nList is empty...");
		return;
	}
	if(loc<1 || loc>listSize)
	{
		printf("\nInvalid location...");
		return;
	}
	for(i=0,p=head;i!=loc-1;i++,p=p->next)
	;
	node=p->next;
	p->next=node->next;
	free(node);
	listSize--;
	printf("\nOne element deleted...");
}
