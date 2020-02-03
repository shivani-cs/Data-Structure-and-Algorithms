/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title-Implement any database using doubly linked list with following options
  	i) Insert a record                  ii) delete a record           iii) modify a record
	iv) Display list forward            v) Display list backward

*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct dll
{
	int accno;
	char custname[30];
	int balance;
	struct dll *prev;
	struct dll *next;
};
typedef struct dll node;
node *head;
char str[20];
node *createnode (int ano, char name[], int bal);
node *create_dll ( );			
void display_dll (node *);
node *insert_dll (node *head);
node *delete_dll (node *head);
void  display_rev_dll (node *head);
node *modify_dll (node *head);
void main()
{
	int ch,ans;
	do
	{
		printf("\n1-To create dll.");
		printf("\n2-To display dll.");
		printf("\n3-To delete dll.");
		printf("\n4-To insert record.");
		printf("\n5-To display reverse dll.");
		printf("\n6-To modify dll.");
		printf("\n7-Exit.");
		printf("\nEnter your choice-");
	    	scanf("%d",&ch);   
	    	switch(ch)
	    	{	
	    		case 1:	head=create_dll();
	    		    	break;   	
	    		case 2: 	display_dll(head);
	    		    	break;
	    		case 3:  	head=delete_dll(head);
	                       	display_dll(head);
		       		break;
		       	case 4:   	head=insert_dll(head);
                           		display_dll(head);     
		             	break;
                		case 5: 	display_rev_dll(head);
	    		    	break;
	        		case 6:	head=modify_dll(head);
				break;   		    
	       		case 7:	exit(0);	    
           		default : printf("Entered Choice is wrong");
	    	}
	    	printf("\nEnter 1 to perform another operation-");
		scanf("%d",&ans);
	 }while(ans==1);
}
node *createnode(int ano,char name[],int bal)
{
	node *temp=NULL; 
	temp = (node *)malloc(sizeof (node));
	if(temp == NULL)
	{
		printf("\nAllocation Failed");
		exit(0);
	}
	else
	{         
		temp->prev=temp->next=NULL;
		temp->accno=ano;
		strcpy(temp->custname, name);
		temp-> balance=bal;
	}    
	return(temp);
}
node *create_dll()
{
	node *h=NULL,*new1,*temp; 
	int i=0,n;
	int ano,bal;
	char name[20];
	printf("\nEnter no of records you want to enter :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter Account Number :");
		scanf("%d",&ano);
		printf("\nEnter Name :");
		scanf("%s",name);
		printf("\nEnter balance : ");
		scanf("%d",&bal);
		temp = new1;
		new1 = createnode(ano,name,bal);
		if(h == NULL)
		{
		    	h=new1;
		    	temp=head;
		}    
		else
		{
			temp->next = new1;
			new1->prev = temp;
		}          
	}
	return(h);
}

void display_dll(node *head)
{
	node *p=head;
    	if(p==NULL)
    	{
        		printf("DLL is empty\n");
	    	return;
    	}
    	printf("\n\t\n");
    	printf("\n\tAccount no\tName\tBalance\n");
    	while(p!=NULL)
	{
    		printf("\t\t%d\t",p->accno);
    		printf("%s\t",p->custname);
    		printf("%d/-\t",p->balance);
    		printf("\n");
        		p=p->next;
	}
	printf("\n\t");
}

node *insert_dll (node *head)
{
	node  *new1, *temp, *p;	  
    	int before_ano;   
    	int ano,bal,ch;
    	char name[20];
    	printf("\nEnter the data  to be inserted\n");
    	printf("\nEnter Account Number :");
	scanf("%d",&ano);
	printf("\nEnter Name :");
	scanf("%s",name);
	printf("\nEnter balance : ");
	scanf("%d",&bal);
    	new1 = createnode(ano,name ,bal);
    	if(head==NULL)
	{
		head = new1;
		return(head);
	}
	printf("Enter your choice");
	printf("\n1-To enter record at the end.\n2-To enter record before any node.\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:	p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new1;
			new1->prev=p;
			return(head);
			break;
		case 2:	printf("\nEnter the account no. before which you want insert the new record:-");
    			scanf("%d",&before_ano);
    			if(before_ano == head->accno)
    			{
        				new1->next = head;                  
        				head->prev= new1;
				head = new1;
				return(head);
    			}
    			else  
    			{
        				p=head;
        				while(p!=NULL)
        				{
					if( p->accno == before_ano)
            				break;
            				p=p->next;
        				}
				temp = p->prev;
	    			temp->next = new1;
       	 			new1->prev = temp;
        				new1->next = p;
        				p->prev =new1;
        				return(head);
     			}
     	}
}

node *delete_dll (node *head)
{    
 	node *p;	
	int flag=0,del_ano;  
    	printf("\nEnter the account no. to be deleted:-");
        	scanf("%d",&del_ano);
	if(head == NULL)
	{
		printf("\nDLL is empty\n");
       	 	return(head);
    	}
    	if(head->next==NULL)
    	{
    		head=NULL;
    		free(head);
    		return(head);
    	}
    	if(del_ano == head->accno)	 
    	{
       		 p=head;
       		 head=head->next;
       		 head->prev= NULL;
		 return(head);
    	}
   	p=head;
    	while(p!=NULL)
    	{
		if( p->accno == del_ano)
       		{
       			flag=1;
       			break;
       		
        		}
        	p=p->next;
    	}
    	if(p->next==NULL)
    	{
    		(p->prev)->next=NULL;
    		free(p);
    		return(head);
    	}
	else	
    	{
		(p->prev)->next = p->next;
        		(p->next)->prev = p->prev; 
        		free(p); 
        		return(head);                                           
    	}
        	printf("\nData not found\n");
}

void  display_rev_dll (node *head)
{

	node *p=head;
    	if(p == NULL)
    	{
        	printf("\nDLL is empty\n");
	    	return;
    	}
    	while(p->next!=NULL)
       		p=p->next;
    	printf("\tAccount no\tName\tBalance\n");
    	while(p!=NULL)
	{
    		printf("\t\t%d\t",p->accno);
    		printf("%s\t",p->custname);
    		printf("%d/-\t",p->balance);
    		printf("\n");
        	p=p->prev;
	}
}

node *modify_dll(node *head)
{
	node *p;
	int mod_ano,amount,ch;
	printf("\nEnter Account Number to modify :- ");
	scanf("%d",&mod_ano);
	for(p=head;p!=NULL&&p->accno!=mod_ano;p=p->next);
	if(p==NULL)
	printf("\nAccount no not found\n");
	else
	{
		printf("\nEnter amount :-");
		scanf("%d",&amount);
		printf("\nCredit or Debit?\n1-Credit\n2-Debit\nEnter your choice :-");
		scanf("%d",&ch);
		if(ch==1)
		{
			if(p->balance > amount)
			{
				p->balance=p->balance+amount;
				printf("\nYour modified details are\n");
				display_dll(head);
			}
			else
			printf("\nInsufficient Balance\n");
		}
		if(ch==2)
		{
			p->balance=p->balance-amount;
			printf("\nYour modified details are\n");
			display_dll(head);
		}
	}
	return (head);
}




