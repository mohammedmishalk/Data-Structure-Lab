#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct {int r,c,v;} term;
typedef struct
{
	int rows,cols,n;
	term terms[100];
}sparse;

void read(sparse*);
void print(sparse);
sparse add(sparse,sparse);
sparse mul(sparse,sparse);

void main()
{
	sparse s1,s2,s3,s4;
	clrscr();
	printf("Enter the first sparse matrix:");
	read(&s1);
	printf("\nEnter the second sparse matrix:");
	read(&s2);
	printf("\nFirst sparse matrix:");
	print(s1);
	printf("\nSecond sparse matrix:");
	print(s2);
	printf("\nMatrix sum:");
	s3=add(s1,s2);
	print(s3);
	printf("\nMatrix product:");
	s4=mul(s1,s2);
	print(s4);
	getch();
}

void read(sparse* s)
{
	int i;
	printf("\nEnter the order: ");
	scanf("%d%d",&s->rows,&s->cols);
	printf("\nEnter the number of non zero elements : ");
	scanf("%d",&s->n);
	printf("\nEnter the details of %d non zero elements rowwise:\n",s->n);
	for(i=0;i<s->n;i++)
	{
		printf("\nRow    : ");
		scanf("%d",&s->terms[i].r);
		printf("Column : ");
		scanf("%d",&s->terms[i].c);
		printf("Value  : ");
		scanf("%d",&s->terms[i].v);
	}
}
void print(sparse s)
{
	int i,j,k;
	for(i=1,k=0;i<=s.rows;i++)
	{
		printf("\n");
		for(j=1;j<=s.cols;j++)
			if(k<s.n && i==s.terms[k].r && j==s.terms[k].c)
				printf("%4d",s.terms[k++].v);
			else printf("   0");
	}
}
sparse add(sparse s1,sparse s2)
{
	sparse s3;
	int i=0,j=0,k=0;
	s3.rows=0;
	if(s1.n==0) return s2;
	if(s2.n==0) return s1;
	if(s1.rows!=s2.rows || s1.cols!=s2.cols)
	{
		printf("\nMatrices can not be added...");
		return s3;
	}
	s3.rows=s1.rows;
	s3.cols=s1.cols;
	while(i<s1.n && j<s2.n)
	{
		if(s1.terms[i].r<s2.terms[j].r || s1.terms[i].r==s2.terms[j].r && s1.terms[i].c<s2.terms[j].c)
			s3.terms[k++]=s1.terms[i++];
		else if(s1.terms[i].r>s2.terms[j].r || s1.terms[i].r==s2.terms[j].r && s1.terms[i].c>s2.terms[j].c)
			s3.terms[k++]=s2.terms[j++];
		else if(s1.terms[i].v+s2.terms[j].v!=0)
		{
			s3.terms[k]=s1.terms[i++];
			s3.terms[k++].v+=s2.terms[j++].v;
		}
		else i++,j++;
	}
	while(i<s1.n) s3.terms[k++]=s1.terms[i++];
	while(j<s2.n) s3.terms[k++]=s2.terms[j++];
	s3.n=k;
	return s3;
}
sparse mul(sparse s1,sparse s2)
{
	sparse s3;
	term t;
	int i,j,k;
	s3.rows=0;
	if(s1.cols!=s2.rows)
	{
		printf("\nMatrices can not be multiplied...");
		return s3;
	}
	s3.rows=s1.rows;
	s3.cols=s2.cols;
	s3.n=0;
	for(i=0;i<s1.n;i++)
	for(j=0;j<s2.n;j++)
	{
		if(s1.terms[i].c!=s2.terms[j].r) continue;
		t.r=s1.terms[i].r;
		t.c=s2.terms[j].c;
		t.v=s1.terms[i].v*s2.terms[j].v;
		for(k=0;k<s3.n;k++)
		if(s3.terms[k].r==t.r && s3.terms[k].c==t.c)
		{
			s3.terms[k].v+=t.v;
			break;
		}
		if(k<s3.n) continue;
		for(k=k-1;k>=0 && (t.r<s3.terms[k].r || (t.r==s3.terms[k].r && t.c<s3.terms[k].c));k--)
			s3.terms[k+1]=s3.terms[k];
		s3.terms[k+1]=t;
		s3.n++;
	}
	return s3;
}
