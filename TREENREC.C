#include<stdio.h>
#include<conio.h>
#include<alloc.h>

typedef struct treeNode* treePointer;
struct treeNode
{
	int data;
	treePointer leftChild,rightChild;
};

treePointer root=NULL;

void create();
void preOrder(treePointer);
void inOrder(treePointer);
void postOrder(treePointer);
void levelOrder(treePointer);

treePointer queue[100];
int front,rear;
#define initq() front=rear=-1
#define addq(node) queue[++rear]=node
#define delq() (front==rear)?NULL:queue[++front]

treePointer stack[100];
int top=-1;
#define push(node) stack[++top]=node
#define pop() (top==-1)?NULL:stack[top--]

void main()
{
	int choice;
	do
	{
		clrscr();
		printf("\n\tBINARY TREE OPERATIONS\n");
		printf("\n\t\t1. Create");
		printf("\n\t\t2. Traverse preorder");
		printf("\n\t\t3. Traverse inorder");
		printf("\n\t\t4. Traverse postorder");
		printf("\n\t\t5. Traverse levelorder");
		printf("\n\t\t6. Exit");
		printf("\n\n\tEnter your choice(1-6) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				preOrder(root);
				break;
			case 3:
				inOrder(root);
				break;
			case 4:
				postOrder(root);
				break;
			case 5:
				levelOrder(root);
				break;
			default:continue;
		}
		getch();
	}while(choice!=6);
}

void create()
{
	int n=0;
	char choice;
	treePointer node,temp;
	if(root!=NULL)
	{
		printf("\nTree already exists...");
		return;
	}
	initq();
	printf("\nEnter the nodes level wise:\n");
	root=(treePointer)malloc(sizeof(*root));
	printf("\nEnter data for the root node : ");
	scanf("%d",&root->data);
	root->leftChild=root->rightChild=NULL;
	n++;
	node=root;
	do
	{
		   printf("\n\nEnter child nodes for node with data %d",node->data);
		   printf("\n\nAdd left child(y/n) : ");
		   choice=getche();
		   if(choice=='y' || choice=='Y')
		   {
			temp=(treePointer)malloc(sizeof(*temp));
			printf("\nEnter data for the left child node : ");
			scanf("%d",&temp->data);
			temp->leftChild=temp->rightChild=NULL;
			node->leftChild=temp;
			addq(temp);
			n++;
		   }
		   printf("\nAdd right child(y/n) : ");
		   choice=getche();
		   if(choice=='y' || choice=='Y')
		   {
			temp=(treePointer)malloc(sizeof(*temp));
			printf("\nEnter data for the right child node : ");
			scanf("%d",&temp->data);
			temp->leftChild=temp->rightChild=NULL;
			node->rightChild=temp;
			addq(temp);
			n++;
		   }
		   node=delq();
	}
	while(node!=NULL);
	printf("\n\nBinary tree created with %d nodes...",n);
}
void preOrder(treePointer node)
{
	if(node==NULL)
	{
		printf("\nTree is empty...");
		return;
	}
	printf("\nPre order traversal :");
	while(1)
	{
		while(node!=NULL)
		{
			printf(" %d",node->data);
			push(node);
			node=node->leftChild;
		}
		node=pop();
		if(!node) break;
		node=node->rightChild;
	}
}
void inOrder(treePointer node)
{
	if(node==NULL)
	{
		printf("\nTree is empty...");
		return;
	}
	printf("\nIn order traversal :");
	while(1)
	{
		while(node!=NULL)
		{
			push(node);
			node=node->leftChild;
		}
		node=pop();
		if(!node) break;
		printf(" %d",node->data);
		node=node->rightChild;
	}
}
void postOrder(treePointer node)
{
	treePointer p;
	if(node==NULL)
	{
		printf("\nTree is empty...");
		return;
	}
	printf("\nPost order traversal :");
	while(1)
	{
		while(node!=NULL)
		{
			push(node);
			node=node->leftChild;
		}
		node=pop();
		if(node->rightChild==NULL)
		{
			printf(" %d",node->data);
			for(p=pop();p!=NULL && p->rightChild==node;p=pop())
			{
				printf(" %d",p->data);
				node=p;
			}
			if(!p) break;
			node=p;
		}
		push(node);
		node=node->rightChild;
	}
}
void levelOrder(treePointer node)
{
	if(node==NULL)
	{
		printf("\nTree is empty...");
		return;
	}
	initq();
	printf("\nLevel order traversal :");
	do
	{
		printf(" %d",node->data);
		if(node->leftChild!=NULL) addq(node->leftChild);
		if(node->rightChild!=NULL) addq(node->rightChild);
		node=delq();
	}
	while(node!=NULL);
}
