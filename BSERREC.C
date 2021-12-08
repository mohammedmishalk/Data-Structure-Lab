#include<stdio.h>
#include<conio.h>

int search(int [],int,int);
int binsearch(int [],int,int,int);

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
	else printf("\n%d is found at position %d in the array.",x,loc+1);
	getch();
}

int search(int a[],int n,int v)
{
	return binsearch(a,0,n-1,v);
}
int binsearch(int a[],int lb,int ub,int v)
{
	int middle=(lb+ub)/2;
	if(lb>ub) return -1;
	else if(a[middle]==v) return middle;
	else
	{
		if(v<a[middle]) ub=middle-1;
		else lb=middle+1;
		return binsearch(a,lb,ub,v);
	}
}