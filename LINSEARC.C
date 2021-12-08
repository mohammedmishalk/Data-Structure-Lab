#include<stdio.h>
#include<conio.h>

int search(int [],int,int);

void main()
{
	int a[10],i,n,x,loc;
	clrscr();
	printf("Enter the size : ");
	scanf("%d",&n);
	printf("\nEnter %d elements into the array:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nEnter the element to be searched : ");
	scanf("%d",&x);
	loc=search(a,n,x);
	if(loc==-1) printf("\n%d is not found.",x);
	else printf("\n%d is found at position %d in the array.",x,loc);
	getch();
}

int search(int a[],int n,int v)
{
	int i;
	for(i=0;i<n && a[i]!=v;i++)
	;
	return i==n?-1:i;
}