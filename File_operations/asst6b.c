#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	char c;
	int character=0,words=0,spaces=0,sentences=0;
	if(argc!=3)
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
		if(isalnum(c))
		{
			character++;
		}
		if(isspace(c))
		{
			spaces++;
			words++;
		}
		if(c=='.')
		{
			sentences++;
		}
	}
	fp2=fopen(argv[2],"w");
	fprintf(fp2,"character=%d,words=%d,spaces=%d,sentences=%d.",character,words,spaces,sentences);
	fclose(fp1);
	fclose(fp2);
}


/*
OUTPUT-

info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ gcc asst6b.c -o count
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ ./count abc.txt a.txt
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ gcc asst6.c -o type
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ ./type a.txt
character=25,words=4,spaces=4,sentences=2.

*/


