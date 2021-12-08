#include<stdio.h>
#include<conio.h>

void sort(int*,int);

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
	int i,j,x;
	for(i=1;i<n;i++)
	{
		x=a[i];
		for(j=i-1;x<a[j] && j>=0;j--)
			a[j+1]=a[j];
		a[j+1]=x;
	}
}

