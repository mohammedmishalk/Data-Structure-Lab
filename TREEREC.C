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
		printf("\n\t\t5. Exit");
		printf("\n\n\tEnter your choice(1-5) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				if(root==NULL) printf("\nTree is empty...");
				else
				{
					printf("\nPreorder traversal is ");
					preOrder(root);
				}
				break;
			case 3:
				if(root==NULL) printf("\nTree is empty...");
				else
				{
					printf("\nInorder traversal is ");
					inOrder(root);
				}
				break;
			case 4:
				if(root==NULL) printf("\nTree is empty...");
				else
				{
					printf("\nPostorder traversal is ");
					postOrder(root);
				}
				break;
			default:continue;
		}
		getch();
	}while(choice!=5);
}

void create()
{
	int n=0;
	char choice;
	treePointer node,temp;
	treePointer queue[50];
	int front=0,rear=0;
	if(root!=NULL)
	{
		printf("\nTree already exists...");
		return;
	}
	printf("\nEnter the nodes level wise:\n");
	root=(treePointer)malloc(sizeof(*root));
	printf("\nEnter data for the root node : ");
	scanf("%d",&root->data);
	root->leftChild=root->rightChild=NULL;
	queue[rear++]=root;
	n++;
	while(front!=rear)
	{
		node=queue[front++];
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
			queue[rear++]=temp;
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
			queue[rear++]=temp;
			n++;
		   }
	}
	printf("\n\nBinary tree created with %d nodes...",n);
}
void preOrder(treePointer node)
{
	if(node==NULL) return;
	printf(" %d",node->data);
	preOrder(node->leftChild);
	preOrder(node->rightChild);
}
void inOrder(treePointer node)
{
	if(node==NULL) return;
	inOrder(node->leftChild);
	printf(" %d",node->data);
	inOrder(node->rightChild);
}
void postOrder(treePointer node)
{
	if(node==NULL) return;
	postOrder(node->leftChild);
	postOrder(node->rightChild);
	printf(" %d",node->data);
}
