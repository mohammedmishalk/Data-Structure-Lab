#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10],b[10],i,j,m,n;
	clrscr();
	printf("Enter the size of first array: ");
	scanf("%d",&m);
	printf("\nEnter %d elements into first array:\n",m);
	for(i=0;i<m;i++)
	scanf("%d",&a[i]);
	printf("\nEnter the size of second array: ");
	scanf("%d",&n);
	printf("\nEnter %d elements into second array:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	for(i=m,j=0;j<n;i++,j++)
	a[i]=b[j];
	printf("\nFirst array after appending second array:\n");
	for(i=0;i<m+n;i++)
	printf("\n%d",a[i]);
	getch();
}
