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
	int i,j,index,temp;
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		if(a[j]<a[index]) index=j;
		if(index==i) continue;
		temp=a[i];
		a[i]=a[index];
		a[index]=temp;
	}
}

