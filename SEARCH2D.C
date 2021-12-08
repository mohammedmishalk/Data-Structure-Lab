#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10][10],i,j,m,n,x,found=0;
	clrscr();
	printf("\nEnter the dimension : ");
	scanf("%d%d",&m,&n);
	printf("\nEnter %d elements row wise : ",m*n);
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	printf("\nElements in the array:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		printf("%4d",a[i][j]);
		printf("\n");
	}
	printf("\nEnter an element to search : ");
	scanf("%d",&x);
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	if(a[i][j]==x)
	{
		found=1;
		goto label;
	}
	label:if(found)
	printf("\n%d is found at row no.%d, column no.%d",x,i+1,j+1);
	else printf("\n%d is not found",x);
	getch();
}
