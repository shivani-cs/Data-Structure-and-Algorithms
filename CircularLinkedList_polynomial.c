/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title- Implement polynomial using CLL and perform
 	i) Addition of Polynomials                        
 	ii) Multiplication of polynomials 
	iii) Evaluation of polynomial.

*/
#include<stdio.h>
#include<stdlib.h>
typedef struct poly
{
  int coeff;
  int pow;
  struct poly *next;
}node;
node *createnode(int c,int p);
node *createlist(node *head);
void display(node *head);
node *padd(node *p1,node *p2);
node *insert(node *head,int power1,float coeff1);
node *pmul(node *p1,node *p2);
float power1(float x,int y);
float eval(node *head,float x);
void main()
{
	int ch,ans,a;
	float evaluate,x;
	node *new1,*head1=NULL,*head2=NULL,*head,*mult;
	printf("\n1-To create first polynomial.");
	printf("\n2-To create second polynomial.");
	printf("\n3-To display first polynomial.");
	printf("\n4-To display second polynomial.\t");
	printf("\n5-To perforn addition of polynomial.\t");
	printf("\n6-To perform multiplication of polynomial.\t");
	printf("\n7-To evaluate 1st polynomial.");
	printf("\n8-Exit.");
	do
	{
	printf("\nEnter your choice-");
	scanf("\t%d",&ch);
	switch(ch)
	{
		case 1:	head1=createlist(head1);
			break;
		case 2:	head2=createlist(head2);
			break;
		case 3:	printf("\nFirst polynomial is-\t");
			display(head1);
			break;
		case 4:	printf("\nSecond polynomial is-\t");
			display(head2);
			break;
		case 5:	head=padd(head1,head2);
			printf("\nAddition of given polynomial is-\t");
			display(head);
			break;
		case 6:	mult=pmul(head1,head2);
			printf("\nMultiplication of given polynomial is-\t");
			display(mult);
			break;
		case 7:	printf("\n1-To evaluate 1st polynomial.\n2-To evaluate 2nd polynomial.\nEnter your choice-");
			scanf("%d",&a);
			printf("\nEnter the value of x-");
			scanf("%f",&x);
			if(a==1)
			evaluate=eval(head1,x);
			else
			evaluate=eval(head2,x);
			printf("value= %f",evaluate);
			break;
		case 8:	exit(0);
		default:	printf("\nChoice is wrong.");
			break;
	}
	printf("\nTo perform another operation press 1-");
	scanf("%d",&ans);
	}while(ans==1);
}
node *createnode(int c,int p)
{
	node *new1;
	new1=(node *)malloc(sizeof(node));
	if(new1==NULL)
	{
		printf("Allocation is failed.");
	}
	new1->coeff=c;
	new1->pow=p;
	new1->next=new1;
	return(new1);
}
node *createlist(node *head)
{
	int n,c,p,i;
	node *new1,*q;
	printf("Enter the no. of terms in polynomial-");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the coefficient and power of the term-");
		scanf("%d%d",&c,&p);
		new1=createnode(c,p);
		if(head==NULL)

		{
			head=new1;
		}
		else if(new1->pow > head->pow)
		{
			q=head;
			while(q->next!=head)
			{
				q=q->next;
			}
			new1->next=head;
			head=new1;
			q->next=head;
		}
		else
		{
			q=head;
			while(q->next!=head && new1->pow <= q->next->pow)
			{
				q=q->next;
			}
			new1->next=q->next;
			q->next=new1;
		}
	}
	return(head);
}
void display(node *head)
{
	node *p=head;
	if(p==NULL)
	{
		printf("\nSLL is empty.");
		return;
	}
	do
	{
		printf("\t%dX^%d",p->coeff,p->pow);
		p=p->next;
		if(p!=head)
		printf("\t+");
	}while(p!=head);
}
node * padd(node *p1,node *p2)
{
	node *p;
	node *head=NULL;
	int pow;float coeff;
 	p=p1->next;
	do     
	{
		head=insert(head,p->pow,p->coeff);
		p=p->next;
	}while(p!=p1->next);
	p=p2->next;
	do  
	{
		head=insert(head,p->pow,p->coeff);
		p=p->next;
	}while(p!=p2->next);
	return(head);
}
node *insert(node *head,int power1,float coeff1)
{
	node *p,*q;
	p=(node*) malloc(sizeof(node));
	p->pow=power1;
	p->coeff=coeff1;
	p->next=NULL;
	if(head==NULL)
	{
   	     	head=p;
	      	head->next=head;
	     	return(head);
     	}
	if(power1<head->pow)
	{
	     	p->next=head->next;
	     	head->next=p;
	     	head=p;
	     	return(head);
	}
	if(power1==head->pow)
	{ 
	      	head->coeff=head->coeff+coeff1;
	      	return(head);
	}
	q=head;
	while(q->next!=head && power1<=q->next->pow) 
	{
 	    	q=q->next;
	    	if(p->pow==q->pow)
	    	{
			q->coeff=q->coeff+coeff1;
		}
	}
	if(power1>q->pow)
	{
		p->next=q->next;
		q->next=p;
	}
	return(head);
}
node *pmul(node *p1,node *p2)
{
	node *p,*q;
	node *head=NULL;
	q=p2->next;
	do
	{
		p=p1->next;
		do
		{
			head=insert(head,p->pow+q->pow,p->coeff*q->coeff);
			p=p->next;
		}while(p!=p1->next);
		q=q->next;
	}while(q!=p2->next);
	return(head);
}
float power1(float x,int y)
{
	int temp,i;
	temp = x;
	for(i=1;i<=y;i++)
	{
		temp = temp*x;
	}
	return(temp);
}
float eval(node *head,float x)
{
	float value=0.00;
	node *p;
	p = head->next;
	do
	{
		value = value + p->coeff * power1(x,p->pow);
		p = p->next;
	}while(p != head->next);
	return(value); 
}
/*
OUTPUT-
1-To create first polynomial.
2-To create second polynomial.
3-To display first polynomial.
4-To display second polynomial.	
5-To perforn addition of polynomial.	
6-To perform multiplication of polynomial.	
7-To evaluate 1st polynomial.
8-Exit.
Enter your choice-1
Enter the no. of terms in polynomial-3

Enter the coefficient and power of the term-3 3

Enter the coefficient and power of the term-2 2

Enter the coefficient and power of the term-1 1

To perform another operation press 1-1

Enter your choice-2
Enter the no. of terms in polynomial-3

Enter the coefficient and power of the term-4 4

Enter the coefficient and power of the term-2 2

Enter the coefficient and power of the term-3 3

To perform another operation press 1-1

Enter your choice-3

First polynomial is-		3X^3	+	2X^2	+	1X^1

To perform another operation press 1-1

Enter your choice-4

Second polynomial is-		4X^4	+	3X^3	+	2X^2

To perform another operation press 1-1

Enter your choice-5

Addition of given polynomial is-		1X^1	+	4X^4	+	6X^3	+	4X^2

To perform another operation press 1-1

Enter your choice-6

Multiplication of given polynomial is-		2X^3	+	12X^7	+	17X^6	+	16X^5	+	7X^4

To perform another operation press 1-1

Enter your choice-7

1-To evaluate 1st polynomial.
2-To evaluate 2nd polynomial.
Enter your choice-1

Enter the value of x-2
value= 68.000000

To perform another operation press 1-1

Enter your choice-7

1-To evaluate 1st polynomial.
2-To evaluate 2nd polynomial.
Enter your choice-2

Enter the value of x-2
value= 192.000000

To perform another operation press 1-1

Enter your choice-8
*/

	
	

