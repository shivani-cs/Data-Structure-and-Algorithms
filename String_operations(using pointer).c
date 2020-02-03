/*
Name- Shivani Suryawanshi
Roll No- SEIT155
Title- 3.B] Implement following operations on string with pointers  (without using the library functions).  
    	i) Length     ii) Palindrome    iii) String comparison      iv) Copy       v) Reverse   vi) Substring
*/

#include<stdio.h>
int length(char *s1);
void compare(char *s1,char *s2);
void conct(char *s1,char *s2);
void copy(char *s1,char *s2);
void reverse(char *s1);
void palindrome(char *s1);
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
int length(char *s1)
{
	int count=0;
	char *p;
	for(p=s1;(*p!='\0');p++)
	{
		count=count+1;
	}
	return count;
}
void compare(char *s1,char *s2)
{
	char *p=s1,*q=s2;
	while((*p==*q)&&(*p!='\0')&&(*q!='\0'))
	{
		p++;
		q++;
	}
	if((*p=='\0')&&(*q=='\0'))
		printf("\nstring s1 & s2 are equal.");
	else
		printf("\nstring s1 & s2 are not equal.");
}
void conct(char *s1,char *s2)
{
	char *p,*q;
	p=s1;
	for(p=s1;*p!='\0';p++)
	{
	}
	q=s2;
	for(q=s2;*q!='\0';q++)
	{
		*p=*q;
		p++;
	}
	*p='\0';
	printf("\nConcanated string is - %s.",s1);
}
void copy(char *s1,char *s2)
{
	char *p,*q;
	p=s1;
	q=s2;
	for(q=s2;*q!='\0';q++)
	{
		*p=*q;
		p++;
	}
	*p='\0';
	printf("Copied string is - %s",s1);
}
void reverse(char *s1)
{
	char *p,*t,ch;
	for(p=s1;*p!='\0';p++)
	{
	}
	p--;
	t=s1;
	while(t<p)
	{
		ch=*t;
		*t=*p;
		*p=ch;
		t++;
		p--;
	}
	printf("\nReverse of string s1 - %s ",s1);
}
void palindrome(char *s1)
{
	char *p,*t;
	p=s1;
	int flag=0;
	for(p=s1;(*p!='\0');p++)
	{
	}
	p--;
	t=s1;
	while(t<p)
	{
		if(*p!=*t)
		{
			flag=1;
			break;
		}
		else
		{
			t++;
			p--;
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
Copied string is - hi

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

Enter the string s1 -hello
Enter the string s2 -he
Substring he occurs at position 2 in string s1.

For another operation press 1
*/	


	


