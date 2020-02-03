/*
Name- Shivani Suryawanshi
Roll No- SEIT155
Title- 3.A] Implement following operations on string without using pointers  (without using the library functions).      
	i) Length     ii) Palindrome    iii) String comparison     iv) Copy      v) Reverse   vi) Substring
*/

#include<stdio.h>
int length(char s1[20]);
void compare(char s1[20],char s2[20]);
void conct(char s1[20],char s2[20]);
void copy(char s1[20],char s2[20]);
void reverse(char s1[20]);
void palindrome(char s1[20]);
void substring(char s1[20], char s2[20]);
void main()
{
	int i,j,k,ch,len,ans;
	char s1[20],s2[20];
printf("Enter 1 for length.\nEnter 2 for compare.\nEnter 3 for concatanation.\nEnter 4 for copy.\nEnter 5 for reverse.\nEnter 6 for palindrome.\nEnter 7 for substring.\n");
	do
	{
		printf("Enter your choice -");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nEnter the string s1 -");
				scanf("%s",s1);
				k=length(s1);
				printf("Length of string is - %d.",k);
				break;
			case 2:	printf("\nEnter the string s1 -");
				scanf("%s",s1);
				printf("Enter the string s2 -");
				scanf("%s",s2);
				compare(s1,s2);
				break;
			case 3:	printf("\nEnter the string s1 -");
				scanf("%s",s1);
				printf("Enter the string s2 -");
				scanf("%s",s2);
				conct(s1,s2);
				break;
			case 4:	printf("\nEnter the string s1 -");
				scanf("%s",s1);
				printf("Enter the string s2 -");
				scanf("%s",s2);
				copy(s1,s2);
				break;
			case 5:	printf("\nEnter the string s1 -");
				scanf("%s",s1);
				reverse(s1);
				break;
			case 6:	printf("\nEnter the string s1 -");
				scanf("%s",s1);
				palindrome(s1);
				break;
			case 7:	printf("\nEnter the string s1 -");
				scanf("%s",s1);
				printf("Enter the string s2 -");
				scanf("%s",s2);
				substring(s1,s2);
				break;
			default:	printf("\nWrong choice");
				break;
				
			
		}
		printf("\nFor another operation press 1 -");
		scanf("%d",&ans);
	}while(ans==1);
}
int length(char s1[20])
{
	int i,count=0;
	for(i=0;(s1[i]!='\0');i++)
	{
		count++;
	}
	return count;
}
void compare(char s1[20],char s2[20])
{
	int i=0;
	while((s1[i]==s2[i])&&(s1[i]!='\0')&&(s2[i]!='\0'))
	{
		i++;
	}
	if((s1[i]=='\0')&&(s2[i]=='\0'))
		printf("\nstring s1 & s2 are equal.");
	else
		printf("\nstring s1 & s2 are not equal.");
}
void conct(char s1[20],char s2[20])
{
	int i,j;
	i=length(s1);
	for(j=0;s2[j]!='\0';j++)
	{
		s1[i]=s2[j];
		i++;
	}
	s1[i]='\0';
	printf("\nConcanated string is - %s.",s1);
}
void copy(char s1[20],char s2[20])
{
	int i;
	for(i=0;s2[i]!='\0';i++)
		s1[i]=s2[i];
	s1[i]!='\0';
	printf("Copied string is - %s",s1);
}
void reverse(char s1[20])
{
	int i,j,k;
	char t;
	k=length(s1);
	k=k-1;
	j=k;
	i=0;
	while(i<j)
	{
		t=s1[i];
		s1[i]=s1[j];
		s1[j]=t;
		i++;
		j--;
	}
	printf("\nReverse of string s1 - %s ",s1);
}
void palindrome(char s1[20])
{
	int i,k,flag=0;
	k=length(s1);
	k=k-1;
	while(i<k)
	{
		if(s1[i]!=s1[k])
		{
			flag=1;
			break;
		}
		else
		{
			i++;
			k--;
		}
	}
	if(flag==1)
	printf("string s1 is not palindrome.");
	else
	printf("String s1 is palindrome.");
}
void substring(char s1[20], char s2[20])
{
	int i=0,j=0;
	while((s1[i]==s2[j])||(s1[i]!=s2[j])&&(s1[i]!='\0')&&(s2[j]!='\0'))
	{
		if(s1[i]!=s2[j])
		{
			i++;
			continue;
		}
		else
		{
			i++;
			j++;
		}
	}
	if(s2[j]=='\0')
	printf("\nSubstring %s occurs at position %d in string s1.",s2,i);
	else
	printf("\nSubstring is not found.");
}
		

/*
OUTPUT-

Enter 1 for length.
Enter 2 for compare.
Enter 3 for concatanation.
Enter 4 for copy.
Enter 5 for reverse.
Enter 6 for palindrome.
Enter 7 for substring.
Enter your choice -1

Enter the string s1 -college
Length of string is - 7.

For another operation press 1 -1
Enter your choice -2

Enter the string s1 -hello
Enter the string s2 -hi
string s1 & s2 are not equal.

For another operation press 1 -1
Enter your choice -3

Enter the string s1 -hello
Enter the string s2 -hi
Concanated string is - hellohi.

For another operation press 1 -1
Enter your choice -4

Enter the string s1 -hello
Enter the string s2 -hi
Copied string is - hillo

For another operation press 1 -1
Enter your choice -5

Enter the string s1 -college
Reverse of string s1 - egelloc 

For another operation press 1 -1
Enter your choice -6

Enter the string s1 -madam
String s1 is palindrome.

For another operation press 1 -1
Enter your choice -7

Enter the string s1 -college
Enter the string s2 -leg
Substring leg occurs at position 6 in string s1.

For another operation press 1 -
*/


	


