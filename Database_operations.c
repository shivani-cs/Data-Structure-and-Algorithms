/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title :- Create a Database using array of structures and perform following operations on it:
       i) Create Database. ii) Display Database. iii) Add record. iv) Search a record. 
       v) Modify a records. vi) Delete a record.
*/

#include<stdio.h>
int count=0;
struct bank
{
	int acc_no;
	char name[40];
	int bal;
};
void Create(struct bank b[]);
void Display(struct bank b[]);
void Add_Record(struct bank b[]);
int Search_Record(struct bank b[],int acc_no);
void Modify_Record(struct bank b[]);
void Delete_Record(struct bank b[]);
void main()
{
	int ch,acc_no;
	int count=0;
	struct bank b[100];
	do
	{
	printf("Menu\n1.Create A Database\n2.Display Record\n3.Add_Record\n4.Search_Record\n5.Modify_Record\n6.Delete_Record\n\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : Create(b);
		break;
		case 2 : Display(b);
		break;
		case 3 : Add_Record(b);
		break;
	        case 4: 
		printf("Enter the acc no you want to search :-");
		scanf("%d",&acc_no);
		Search_Record(b,acc_no);
		break;
		case 5 : Modify_Record(b);
		break;
		case 6 : Delete_Record(b);
	        break;
		default :
		printf("Wrong Choice");
	}	
	}while(ch>0 && ch<6);
}
void Create(struct bank b[])
{
		int num,i;
		printf("Entre how many members you want : ");
		scanf("%d",&num);
		for(i=0;i<num;i++)
		{
			Add_Record(b);
		}	
		Display(b);
}
void Display(struct bank b[])
{
		
		int i;
		printf("\n\t\t\tDisplaying records\n\n");
		printf("\tAccount no\t\tName\t\tBalance");
		for(i=0;i<count;i++)
		{
			printf("\n\t%d",b[i].acc_no);
			printf("\t\t\t%s",b[i].name);
			printf("\t\t%d/-\n",b[i].bal);
		}
}
void Add_Record(struct bank b[])
{
		if(count>=100)
		printf("Database is Full");
		else
		{
		printf("\nEnter Account no : ");
		scanf("%d",&b[count].acc_no);
		printf("\nEnter Name : ");
		scanf("%s",b[count].name);
		printf("\nEnter Balance : ");
		scanf("%d",&b[count].bal);
		count++;
		}	
	
		
}
int Search_Record(struct bank b[],int acc_no)
{
		int i,flag,recno;
		flag=0;
		for(i=0;i<count;i++)
		{
			if(acc_no==b[i].acc_no)
			{
				flag=1;
				recno=i;
				break;
			}
		}
		if(flag==0)
		{
			printf("Record absent in database");
			return(-999);
		}
		else
		{
			printf("Record is present\n\n");
			printf("Details of User having Account no %d\n",acc_no);
			printf("\tAccount no\t\tName\t\tBalance");
			printf("\n\t%d",b[i].acc_no);
			printf("\t\t\t%s",b[i].name);
			printf("\t\t%d\n",b[i].bal);
			return(recno);
		}
}
void Modify_Record(struct bank b[])
{
	int i,recno,acc_no;
	int ch;
	int amt;
	printf("Enter the Account no :-");
	scanf("%d",&acc_no);
	recno=Search_Record(b,acc_no);
	if(recno==-999)
	{  
		printf("Account no not found");
		return;
	}
	printf("Enter the amount :-");
	scanf("%d",&amt);
	printf("Enter the Choice\n1.Credit\n2.Debit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 :
	{
		b[recno].bal=b[recno].bal+amt;
		break;
	}
	case 2 :
	{
		if (amt>b[recno].bal)
		{
			printf("Balance is less");
			return;
		}
		b[recno].bal=b[recno].bal-amt;	
		break;
	}
	}
	printf("Your new balance is :-");    
	printf("%d\n",b[recno].bal); 
}
void Delete_Record(struct bank b[])  
{
	int i,recno,acc_no;
	printf("Enter the Account no :-");
	scanf("%d",&acc_no);
	recno=Search_Record(b,acc_no);
	if(recno==-999)
	{  
		printf("Account no not found");
                return;
        }
	for(i=recno;i<count;i++)
	{
		b[i]=b[i+1];
		count=count-1;
	}
	Display(b);
}
/*OUTPUT:
guest-Ngh0Aw@CC:~$ cd Desktop
guest-Ngh0Aw@CC:~/Desktop$ gcc assignment4.c
guest-Ngh0Aw@CC:~/Desktop$ ./a.out
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

1
Entre how many members you want : 2

Enter Account no : 1234

Enter Name : Trishala

Enter Balance : 3000

Enter Account no : 4321

Enter Name : Sanchita

Enter Balance : 4000

			Displaying records

	Account no		Name		Balance
	1234			Trishala		3000/-

	4321			Sanchita		4000/-
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

2

			Displaying records

	Account no		Name		Balance
	1234			Trishala		3000/-

	4321			Sanchita		4000/-
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

3

Enter Account no : 4123

Enter Name : Neha

Enter Balance : 5000
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

2

			Displaying records

	Account no		Name		Balance
	1234			Trishala		3000/-

	4321			Sanchita		4000/-

	4123			Neha		5000/-
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

4
Enter the acc no you want to search :-4321
Record is present

Details of User having Account no 4321
	Account no		Name		Balance
	4321			Sanchita		4000
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

5
Enter the Account no :-1234
Record is present

Details of User having Account no 1234
	Account no		Name		Balance
	1234			Trishala		3000
Enter the amount :-2000
Enter the Choice
1.Credit
2.Debit
1
Your new balance is :-5000
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

2

			Displaying records

	Account no		Name		Balance
	1234			Trishala		5000/-

	4321			Sanchita		4000/-

	4123			Neha		5000/-
Menu
1.Create A Database
2.Display Record
3.Add_Record
4.Search_Record
5.Modify_Record
6.Delete_Record

6
Enter the Account no :-4123
Record is present

Details of User having Account no 4123
	Account no		Name		Balance
	4123			Neha		5000

			Displaying records

	Account no		Name		Balance
	1234			Trishala		5000/-

	4321			Sanchita		4000/-
*/
