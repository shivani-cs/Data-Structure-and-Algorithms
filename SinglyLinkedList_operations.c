/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title-  8.Implement a singly linked list with following options
	i) Insertion of a node at any location     ii) Deletion of a node from any location   
	iii) display a list    iv) Display in reverse     v) Reverse the list
*/


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct stud
{
  int rno;
  char name[20];
  int marks;
  struct stud *next;
}node;
node *create();
node *insert(node *head);
void display(node *head);
void modify(node *head);
node *delete(node *head);
void search(node *head);
void display_rev(node *head);
node *revert(node *head);
void main()
{
	int ch,ans;
	node *head;
	printf("\nprint your choice");
	printf("\n1-To create sll.");
	printf("\n2-Insert a new record.");
	printf("\n3-To modify the record.");
	printf("\n4-To delete the record.");
	printf("\n5-To search the record.");
	printf("\n6-Display all student record.");
	printf("\n7-Display all student record in reverse order.");
	printf("\n8-To revert SLL.");
	printf("\n9-Quit.\t");
	scanf("%d",&ch);
	do
	{
	switch(ch)
	{
		case 1: 	head=create();
			break;
		case 2: 	head=insert(head);
			break;
		case 3:	modify(head);
			break;
		case 4: 	head=delete(head);
			break;
		case 5: 	search(head);
			break;	
		case 6:    display(head);
			break;
		case 7:	display_rev(head);
			break;
		case 8:	head=revert(head);
			break;
		case 9:	exit(0);
		default: 	printf("\nChoice is wrong.");
			break;
	}
	printf("\nTo perform another operation press 1-");
	scanf("%d",&ans);
	}while(ans==1);
}
node *create()
{
	node *head;
	head=NULL;
	return (head);
}
node *insert(node *head)
{
	node *new1,*prev,*p;
	new1=(node *)malloc(sizeof(node));
	printf("\nEnter the data-");
	scanf("%d%s%d",&new1->rno,new1->name,&new1->marks);
	if(head==NULL)
	{
		new1->next=NULL;
		head=new1;
	}
	else if(new1->rno<=head->rno)
	{
		new1->next=head;
		head=new1;
	}
	else
	{
		p=prev=head;
		while( p!=NULL && new1->rno>p->rno )
		{
			
			prev=p;
			p=p->next;
		}
		new1->next=p;
		prev->next=new1;
		
	}
 	return (head);
}
void display(node *head)
{
	node *p=head;
	printf("r_no.\tName\tMarks\n");
	if(p==NULL)
	{
		printf("\nSLL is empty.");
		return;
	}
	while(p!=NULL)
	{
		printf("\n%d\t%s\t%d",p->rno,p->name,p->marks);
		p=p->next;
	}
}
void modify(node *head)
{
	node *p=head;
	int roll_no;
	if(p==NULL)
	{
		printf("\nSLL is empty.");
		return;
	}
	printf("\nEnter the roll no. of record which you want to modify.");
	scanf("%d",&roll_no);
	while(p!=NULL)
	{
		if(p->rno==roll_no)
		{
			printf("\nEnter the new information.");
			printf("\nName-");
			scanf("%s",p->name);
			printf("\nMarks-");
			scanf("%d",&p->marks);
			return;
		}
		p=p->next;
	}
	printf("Record is not found.");
}
node *delete(node *head)
{
	node *p,*prev;
	int roll_no;
	if(head==NULL)
	{
		printf("SLL is empty.");
		return(head);
	}
	printf("Enter the roll no. of the record which you want to delete.");
	scanf("%d",&roll_no);
	if(head->rno==roll_no)
	{
		p=head;
		head=head->next;
		free(p);
		return(head);
	}
	p=prev=head;
	while(p!=NULL)
	{
		if(p->rno==roll_no)
		{
			prev->next=p->next;
			free(p);
			return(head);
		}
		prev=p;
		p=p->next;
	}
}
void search(node *head)
{
	node *p=head;
	int roll_no;
	if(p==NULL)
	{
		printf("\nSLL is empty.");
		return;
	}
	printf("\nEnter the roll no. of record which you want to search-");
	scanf("%d",&roll_no);
	while(p!=NULL)
	{
		if(p->rno==roll_no)
		{
			printf("Record is found.");
			printf("\n%d\t%s\t%d",p->rno,p->name,p->marks);
			return;
		}
		p=p->next;
	}
	printf("Record is not found.");
}
void display_rev(node *head)
{
	node *p=head;
	printf("r_no.\tName\tMarks\n");
	if(head->next!=NULL)
	{
		display_rev(head->next);
	}
	printf("\n%d\t%s\t%d",p->rno,p->name,p->marks);
}
node *revert(node *head)
{
	node *p,*q,*r;
	p=head;
	q=NULL;
	printf("r_no.\tName\tMarks\n");
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	p=q;
	while(p!=NULL)
	{
		printf("\n%d\n%s\n%d",p->rno,p->name,p->marks);
		p=p->next;
	}
}
		
			
	
	
			
			
		
			

