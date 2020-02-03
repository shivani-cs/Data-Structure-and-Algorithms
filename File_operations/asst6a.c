#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	char c;
	if(argc!=3)
	{
		printf("Argument count is not correct.\n");
		exit(0);
	}
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	if(fp1==NULL||fp2==NULL)
	{
		printf("Error in opening file.");
		exit(0);
	}
	while((c=getc(fp1))!=EOF)
	{
		putc(c,fp2);
	}
	fclose(fp1);
	fclose(fp2);
}


/*
OUTPUT-

info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ gcc asst6.c -o type
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ ./type pqr.txt
priyanka tikone.
SE IT 157.
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ ./type ab.txt
shivani
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ gcc asst6a.c -o copy
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ ./copy pqr.txt ab.txt
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ gcc asst6.c -o type
info-12@info12-ThinkCentre-M60e:~/Documents/shivani$ ./type ab.txt
priyanka tikone.
SE IT 157.

*/
