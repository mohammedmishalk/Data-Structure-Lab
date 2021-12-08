#include<stdio.h>
#include<conio.h>

void main()
{
	struct {int r,c,v;} terms[10];
	int rows,cols,n,i,j,k;
	clrscr();
	printf("Enter the order of the sparse matrix : ");
	scanf("%d%d",&rows,&cols);
	printf("\nEnter the number of non zero elements : ");
	scanf("%d",&n);
	printf("\nEnter the details of %d non zero elements rowwise:\n",n);
	for(i=0;i<n;i++)
	{
		printf("\nRow    : ");
		scanf("%d",&terms[i].r);
		printf("Column : ");
		scanf("%d",&terms[i].c);
		printf("Value  : ");
		scanf("%d",&terms[i].v);
	}
	printf("\nThe sparse matrix:\n\n");
	for(i=1,k=0;i<=rows;i++)
	{
		for(j=1;j<=cols;j++)
			if(k<n && i==terms[k].r && j==terms[k].c)
				printf("%4d",terms[k++].v);
			else printf("   0");
		printf("\n");
	}
	getch();
}
