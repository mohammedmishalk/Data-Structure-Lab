#include<stdio.h>
#include<conio.h>

int search(int [],int,int);

void main()
{
	int a[10],i,n,x,loc;
	clrscr();
	printf("Enter the size : ");
	scanf("%d",&n);
	printf("\nEnter %d elements into the array in ascending order:\n",n);
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
	int lb,ub,middle;
	lb=0;
	ub=n-1;
	while(lb<=ub)
	{
		middle=(lb+ub)/2;
		if(a[middle]==v) return middle;
		if(v<a[middle]) ub=middle-1;
		else lb=middle+1;
	}
	return -1;
}