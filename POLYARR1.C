#include<stdio.h>
#include<conio.h>

typedef struct {int coef,exp;} polynomial;

void read(polynomial*,int);
void print(polynomial*,int);

void main()
{
	polynomial p1[10],p2[10],p3[20],p4[50],t;
	int n1,n2,n3,n4,i,j,k;
	clrscr();
	printf("Number of terms in first polynomial : ");
	scanf("%d",&n1);
	printf("\nEnter %d terms for first polynomial:\n",n1);
	read(p1,n1);
	printf("\nNumber of terms in second polynomial : ");
	scanf("%d",&n2);
	printf("\nEnter %d terms for second polynomial:\n",n2);
	read(p2,n2);
	i=j=n3=0;
	while(i<n1 && j<n2)
	{
		if(p1[i].exp>p2[j].exp)
			p3[n3++]=p1[i++];
		else if(p1[i].exp<p2[j].exp)
			p3[n3++]=p2[j++];
		else if(p1[i].coef+p2[j].coef!=0)
		{
			p3[n3]=p1[i++];
			p3[n3++].coef+=p2[j++].coef;
		}
		else i++,j++;
	}
	while(i<n1) p3[n3++]=p1[i++];
	while(j<n2) p3[n3++]=p2[j++];
	for(i=0,n4=0;i<n1;i++)
	for(j=0;j<n2;j++)
	{
		t.coef=p1[i].coef*p2[j].coef;
		t.exp=p1[i].exp+p2[j].exp;
		for(k=0;k<n4 && p4[k].exp!=t.exp;k++)
		;
		if(k==n4) p4[n4++]=t;
		else p4[k].coef+=t.coef;
	}
	printf("\nFirst polynomial   : ");
	print(p1,n1);
	printf("\nSecond polynomial  : ");
	print(p2,n2);
	printf("\nPolynomial sum     : ");
	print(p3,n3);
	printf("\nPolynomial product : ");
	print(p4,n4);
	getch();
}

void read(polynomial p[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nCoefficient : ");
		scanf("%d",&p[i].coef);
		printf("Exponent    : ");
		scanf("%d",&p[i].exp);
	}
}
void print(polynomial p[],int n)
{
	int i;
	if(p[0].coef==-1) printf("-");
	else if(p[0].coef!=1) printf("%d",p[0].coef);
	if(p[0].exp==1) printf("x");
	else if(p[0].exp!=0) printf("x^%d",p[0].exp);
	else if(p[0].coef==-1 || p[0].coef==1) printf("1");
	for(i=1;i<n;i++)
	{
		if(p[i].coef>0) printf("+");
		if(p[i].coef==-1) printf("-");
		else if(p[i].coef!=1) printf("%d",p[i].coef);
		if(p[i].exp==1) printf("x");
		else if(p[i].exp!=0) printf("x^%d",p[i].exp);
		else if(p[i].coef==-1 || p[i].coef==1) printf("1");
	}
}
