#include<stdio.h>
#include<conio.h>
#include<alloc.h>

typedef struct node* polynomial;

struct node
{
	int coef,exp;
	polynomial next;
};

void main()
{
	polynomial p,t;
	int i,n;
	clrscr();
	printf("Number of terms in the polynomial : ");
	scanf("%d",&n);
	printf("\nEnter %d terms for the polynomial:\n",n);
	p=(polynomial)malloc(sizeof(*p));
	printf("\nCoefficient : ");
	scanf("%d",&p->coef);
	printf("Exponent    : ");
	scanf("%d",&p->exp);
	p->next=NULL;
	t=p;
	for(i=0;i<n-1;i++)
	{
		t->next=(polynomial)malloc(sizeof(*p));
		t=t->next;
		printf("\nCoefficient : ");
		scanf("%d",&t->coef);
		printf("Exponent    : ");
		scanf("%d",&t->exp);
		t->next=NULL;
	}
	printf("\nThe polynomial : ");
	if(p->exp==0) printf("%d",p->coef);
	else if(p->exp==1) printf("%dx",p->coef);
	else printf("%dx^%d",p->coef,p->exp);
	for(t=p->next;t!=NULL;t=t->next)
	{
		if(t->coef>0) printf("+");
		if(t->exp==0) printf("%d",t->coef);
		else if(t->exp==1) printf("%dx",t->coef);
		else printf("%dx^%d",t->coef,t->exp);
	}
	getch();
}
