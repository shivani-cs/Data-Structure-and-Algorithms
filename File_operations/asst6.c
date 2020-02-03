/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title- a) Write C program to implement TYPE and COPY commands of  
     	DOS using command line arguments.
       b) Find out number of characters, words, spaces and sentences form 
   	a file and write result in another file.
*/
#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	FILE *fp1;
	char c;
	if(argc!=2)
	{
		printf("Argument count is not correct.\n");
		exit(0);
	}
	fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		printf("Error in opening file.");
		exit(0);
	}
	while((c=getc(fp1))!=EOF)
	{
		putchar(c);
	}
	fclose(fp1);
}


/*

OUTPUT-

ThinkCentre-M60e:~/Documents/shivani$ gcc asst6.c -o type
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ ./type abc.txt
Shivani Suryawanshi.
SEIT 155.

*/
