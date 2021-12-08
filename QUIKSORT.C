#include<stdio.h>
#include<conio.h>

void sort(int*,int);
void qsort(int*,int,int);

void main()
{
	int a[10],n,i;
	clrscr();
	printf("Enter the size : ");
	scanf("%d",&n);
	printf("\nEnter %d elements into the array :\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nArray before sorting :");
	for(i=0;i<n;i++)
	printf(" %d",a[i]);
	sort(a,n);
	printf("\n\nArray after sorting  :");
	for(i=0;i<n;i++)
	printf(" %d",a[i]);
	getch();
}

void sort(int a[],int n)
{
	qsort(a,0,n-1);
}

void qsort(int a[],int lb,int ub)
{
	int up,down,c,temp;
	if(lb>=ub) return;
	c=a[lb];
	up=lb;
	down=ub;
	while(1)
	{
		while(a[up]<=c && up<down) up++;
		while(a[down]>c) down--;
		if(up>=down) break;
		temp=a[up];
		a[up]=a[down];
		a[down]=temp;
	}
	a[lb]=a[down];
	a[down]=c;
	qsort(a,lb,down-1);
	qsort(a,down+1,ub);
}

