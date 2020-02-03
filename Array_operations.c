/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title-  1. Represent sets using one dimensional arrays and implement functions to perform    
        	 i) union ii) intersection, iii) difference, iv) symmetric difference of two sets.
*/

#include<stdio.h>
void union1(int a[20],int b[20],int n1,int n2);                   //union1 function declaration
void intersection(int a[20],int b[20],int n1,int n2);		//intersectin function declaration
void difference(int a[20],int b[20],int n1,int n2);		//difference function declaration
void symmetricdifference(int a[20],int b[20],int n1,int n2);	//symmetric difference function declaration
void main()          					//main function starts
{
	int m1,m2,i=0,j=0,x[20],y[20],ch,ans;
	printf("Enter the no. of elements in array a & b.");
	scanf("%d%d",&m1,&m2);
	printf("\nEnter the element of set X");
	for(i=0;i<m1;i++)
    {
		scanf("%d",&x[i]);
	}
	printf("array x is \n");			//To diplay set a
	for(i=0;i<m1;i++)
	{
		printf("\t%d",x[i]);
	}
	printf("\nEnter the element of set Y  ");
	for(j=0;j<m2;j++)
	{
		scanf("%d",&y[j]);
	}
	printf("array y is \n");			//To display set B
	for(j=0;j<m2;j++
	{
		printf("\t%d",y[j]);
	}
	printf("\nEnter 1 for union,\n 2 for intersection.\n 3 for difference.\n 4 for symmetric difference.\n");
	do
	{
		printf("enter the choice-\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:union1(x,y,m1,m2);
			break;
			case 2:intersection(x,y,m1,m2);
			break;
			case 3:difference(x,y,m1,m2);
			break;
			case 4:symmetricdifference(x,y,m1,m2);
			break;
			default:printf("choice is wrong");
		}
		printf("\nif you want to cuntinue press 1.\n");
		scanf("%d",&ans);
	}while(ans==1);
	
}						//main function ends
	void union1(int a[20],int b[20],int n1,int n2)	//union1 function definition starts
	{					//Function to determine union of
						//two sets a & b stored in array
	int c[20],k=0,flag,i,j;
	for(i=0;i<n1;i++)
	{
		c[k]=a[i];
		k++;
	}
	for(j=0;j<n2;j++)
	{
		flag=0;
		for(i=0;i<n1;i++)
		{
			if(b[j]==a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		c[k]=b[j];
		k++;
		}
	}
	printf("Union set is\n ");		//union set displays all elements in a & b
	for(i=0;i<k;i++)
	{
		printf("%d\t",c[i]);
	}
	}					//union1 function ends
	
	void intersection(int a[20],int b[20],int n1,int n2)//intersect function definition starts
	{				        //Function to determine intersection  
					        //of two sets a & b                             
	int c[20],k=0,i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(b[j]==a[i])
			{
				c[k]=b[j];
				k++;
				break;
			}
		}
	}
	printf("Intersection set is\n ");	//Intersection set displays 
					//common elements in a & b
	for(i=0;i<k;i++)
	{
		printf("%d\t",c[i]);
	}
	}				//intersection function ends
	
	void difference(int a[20],int b[20],int n1,int n2)//difference function declaration starts
	{				//Function determines difference of two 
					//sets a & b stored in array
	int c[20],k=0,flag,i,j;
	for(i=0;i<n1;i++)
	{
		flag=0;
		for(j=0;j<n2;j++)
		{
			if(b[j]==a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		c[k]=a[i];
		k++;
		}
	}
	printf("Difference set is\n ");		//Difference set displays the elements 
					//which are in set a & not in set b
	for(j=0;j<k;j++)
	{
		printf("%d\t",c[j]);
	}
	}  					    //difference function ends
	
	void symmetricdifference(int a[20],int b[20],int n1,int n2)//symmetric difference 
	{					    //function definition starts
	int c[20],k=0,flag,i,j;
	for(i=0;i<n1;i++)
	{
		flag=0;
		for(j=0;j<n2;j++)
		{
			if(b[j]==a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		c[k]=a[i];
		k++;
		}
	}
	for(j=0;j<n2;j++)
	{
		flag=0;
		for(i=0;i<n1;i++)
		{
			if(b[j]==a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		c[k]=b[j];
		k++;
		}
	}
	printf("Symmetric difference set is\n ");	//Symmetric difference set displays uncommon 
					//elements in set a& b
	for(j=0;j<k;j++)
	{
		printf("%d\t",c[j]);
	}
	} 				//symmetric difference function ends
	

























/*OUTPUT-
	
Enter the no. of elements in array a & b.
8 7

Enter the element of set X
92 11 24 76 89 44 39 3
array x is 
	92	11	24	76	89	44	39	3
Enter the element of set Y  
88 55 39 41 24 51 11
array y is 
	88	55	39	41	24	51	11
Enter 1 for union,
 2 for intersection.
 3 for difference.
 4 for symmetric difference.
enter the choice-
1
Union set is
 92	11	24	76	89	44	39	3	88	55	41	51	
if you want to cuntinue press 1.
1
enter the choice-
2
Intersection set is
 11	24	39	
if you want to cuntinue press 1.
1
enter the choice-
3
Difference set is
 92	76	89	44	3	
if you want to cuntinue press 1.
1
enter the choice-
4
Symmetric difference set is
 92	76	89	44	3	88	55	41	51	
if you want to cuntinue press 1.
*/



	




