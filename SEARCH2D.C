#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10][10],i,j,m,n,x,count=0;
	clrscr();
	printf("\nEnter the Row and column : ");
	scanf("%d%d",&m,&n);
	printf("\nEnter %d elements : ",m*n);
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
  }
}

	printf("\nEnter an element to search : ");
	scanf("%d",&x);
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	if(a[i][j]==x)
	{
		printf("Item found at [%d, %d] \n", i, j);
            count++;
	}
}
}
       if(count==0)
    printf("Item Not found");

  getch();
}
