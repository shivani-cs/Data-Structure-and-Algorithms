/*
Name:Shivani Suryawanshi;
Roll No:SEIT155;
Title-	a) Sort the set of strings in ascending order using Bubble sort and  
     	  descending order by using Selection sort.
	b) Search for particular string using binary search.
*/
#include<stdio.h>
#include<string.h>
void bubblesort(char s1[][20],int n);
void selectionsort(char s1[][20],int n);
int search_rec(char s1[][20],int first,int last,char s2[]);
int search_nonrec(char s1[][20],int n,char s2[]);
void main()
{
	int n,ch,ans,i,p,first,last;
	char s1[20][20],s2[20];
	printf("Enter how many strings you want\t");
	scanf("%d",&n);
	printf("Enter the strings\n");
	for(i=1;i<=n;i++)
	{
		scanf("%s",s1[i]);
	}
	printf("strings are\n");
	for(i=1;i<=n;i++)
	{
		printf("%s\n",s1[i]);
	}
	printf("Enter 1 for bubble sort\nEnter 2 for selection sort\nEnter 3 for recursive binary search\nEnter 4 for nonrecursive binary search\n");
	do
	{
		printf("Enter your choice\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:bubblesort(s1,n);
			       break;
			case 2:selectionsort(s1,n);
			       break;
			case 3:printf("Enter the string which you want to search\n");
			       scanf("%s",s2);
			       bubblesort(s1,n);
			       first=1;
			       last=n;
			       p=search_rec(s1,first,last,s2);
			       if(p>-1)
			       printf("given string is present at position %d\n",p);
			 	   else
			 	   printf("string is not present\n");
			       break;
			case 4:printf("Enter the string which you want to search\n");
			       scanf("%s",s2);
			       bubblesort(s1,n);
			       p=search_rec(s1,first,last,s2);
			       if(p>-1)
			       printf("given string is present at position %d\n",p);
			 	   else
			 	   printf("string is not present\n");
			       break;
		}
		printf("To continue press 1\t");
		scanf("%d",&ans);
	}
	while(ans==1);
}
void bubblesort(char s1[][20],int n)
{
	int i,passcnt=0,compcnt=0,j;
	char temp[20];
	for(i=1;i<=n;i++)
	{
		passcnt++;
		for(j=1;j<=n-1;j++)
		{
			compcnt++;
			if(strcmp(s1[j],s1[j+1])>0)
			{
				strcpy(temp,s1[j]);
				strcpy(s1[j],s1[j+1]);
				strcpy(s1[j+1],temp);
			}
		}
	}
	printf("sorted strings are\n");
	for(i=1;i<=n;i++)
	{
		printf("%s\n",s1[i]);
	}
}
void selectionsort(char s1[][20],int n)
{
	int i,passcnt=0,compcnt=0,j,min;
	char temp[20];
	for(i=1;i<=n;i++)
	{
		passcnt++;
		min=i;
		for(j=i+1;j<=n;j++)
		{
			compcnt++;
			if(strcmp(s1[j],s1[min])>0)
			{
				min=j;
				strcpy(temp,s1[i]);
				strcpy(s1[i],s1[min]);
				strcpy(s1[min],temp);
			}
		}
	}
	printf("sorted strings are\n");
	for(i=1;i<=n;i++)
	{
		printf("%s\n",s1[i]);
	}
}
int search_rec(char s1[][20],int first,int last,char s2[])
{
	int middle;
	int p;
	p=-1;
	if(first>last)
	{
		return(-1);
	}
	else
	{
		middle=(first+last)/2;
		if(strcmp(s2,s1[middle])==0)
		p=middle;
		else if(strcmp(s2,s1[middle])>0)
		return(search_rec(s1,middle+1,last,s2));
		else if(strcmp(s2,s1[middle])<0)
		return(search_rec(s1,first,middle-1,s2));
	}
	return p;
}
int search_nonrec(char s1[][20],int n,char s2[])
{	
	int middle,first,last;
	first=1;
	last=n;
	int p;
	p=-1;
	while(last>first)
	{
		middle=(first+last)/2;
		if(strcmp(s2,s1[middle])==0)
		{
			p=middle;
			break;
		}
		else if(strcmp(s2,s1[middle])>0)
		first=middle+1;
		else if(strcmp(s2,s1[middle])<0)
		last=middle-1;
	}
	return p;
}


/*OUTPUT:
Enter how many strings you want	3
Enter the strings
hello
hay
hi
strings are
hello
hay
hi
Enter 1 for bubble sort
Enter 2 for selection sort
Enter 3 for recursive binary search
Enter 4 for nonrecursive binary search
Enter your choice	1
sorted strings are
hay
hello
hi
To continue press 1	1
Enter your choice	2
sorted strings are
hi
hello
hay
To continue press 1	1
Enter your choice	3
Enter the string which you want to search
hi
sorted strings are
hay
hello
hi
given string is present at position 3
To continue press 1	1
Enter your choice	3
Enter the string which you want to search
jfj
sorted strings are
hay
hello
hi
string is not present
To continue press 1	1
Enter your choice	4
Enter the string which you want to search
hello
sorted strings are
hay
hello
hi
given string is present at position 2
To continue press 1	1
Enter your choice	4
Enter the string which you want to search
jg
sorted strings are
hay
hello
hi
string is not present
To continue press 1	
*/

		
