/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title-  7.Represent sparse matrix using two dimensional array or structure and perform simple and fast transpose
*/

#include<stdio.h>
struct sparse
{
	int row;
	int col;
	int val;
};
void getdata(struct sparse a[20]);
void simple_transpose(struct sparse a[20]);
void fast_transpose(struct sparse a[20]);
void main()
{
	int ch,ans;
	struct sparse a[20],b[20];
	
	do
	{
		printf("\nEnter 1 to accept sparse matrix\nEnter 2 for simple transpose\nEnter 3 for fast transpose\n");
		printf("\nEnter your choice\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:getdata(a);
			       break;
			case 2:simple_transpose(a);
			       break;
			case 3:fast_transpose(a);
				   break;
			default:printf("Wrong choice");
		}
		printf("To continue enter 1\t");
		scanf("%d",&ans);
	}
	while(ans==1);
}
void getdata(struct sparse a[20])
{
	int t1,i;
	printf("Enter no of rows\t");
	scanf("%d",&a[0].row);
	printf("Enter no of columns\t");
	scanf("%d",&a[0].col);
	printf("Enter no of non zero values you want in matrix\t");
	scanf("%d",&a[0].val);
	t1=a[0].val;
	printf("Enter the row no,column no and value\n");
	for(i=1;i<=t1;i++)
	{
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
	}
	printf("The sparse matrix is\n");
	for(i=0;i<=t1;i++)
	{
		printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
	}
}
void simple_transpose(struct sparse a[20])
{
	struct sparse b[20];
	int c,q=1,i,n,t;
	n=a[0].col;
	t=a[0].val;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].val=a[0].val;
	if(t==0)
	return;
	for(c=0;c<=n;c++)
	{
		for(i=1;i<=t;i++)
		{
			if(a[i].col==c)
			{
				b[q].col=a[i].row;
				b[q].row=a[i].col;
				b[q].val=a[i].val;
				q++;
			}
		}
	}
	printf("After simple transpose matrix is\n");
	for(i=0;i<=t;i++)
	{
		printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
	}
}
void fast_transpose(struct sparse a[20])
{
	int i,j,n,t,k;
	struct sparse b[20];
	n=a[0].col;
	t=a[0].val;
	int S[n];
	int T[n];
	for(i=0;i<n;i++)
	{
		S[i]=0;
		T[i]=0;
	}
	b[0].row=n;
	b[0].col=a[0].row;
	b[0].val=t;
	if(t==0)
	return;
	for(i=1;i<=t;i++)
	{
		S[a[i].col]++;
	}
	T[0]=1;
	for(i=1;i<n;i++)
	{
		T[i]=T[i-1]+S[i-1];
	}
	for(i=1;i<=t;i++)
	{
		k=a[i].col;
		j=T[k];
		b[j].row=a[i].col;
		b[j].col=a[i].row;
		b[j].val=a[i].val;
		T[k]++;
	}
	printf("After fast transpose matrix is\n");
	for(i=0;i<=t;i++)
	{
		printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
	}			
}	
	

/* OUTPUT:
Enter 1 to accept sparse matrix
Enter 2 for simple transpose
Enter 3 for fast transpose

Enter your choice	1
Enter no of rows	4
Enter no of columns	4
Enter no of non zero values you want in matrix	5
Enter the row no,column no and value
0 0 9
0 1 15
1 2 4
2 1 2
3 3 2
The sparse matrix is
4	4	5
0	0	9
0	1	15
1	2	4
2	1	2
3	3	2
To continue enter 1	1

Enter 1 to accept sparse matrix
Enter 2 for simple transpose
Enter 3 for fast transpose

Enter your choice	2
After simple transpose matrix is
4	4	5
0	0	9
1	0	15
1	2	2
2	1	4
3	3	2
To continue enter 1	1

Enter 1 to accept sparse matrix
Enter 2 for simple transpose
Enter 3 for fast transpose

Enter your choice	3
After fast transpose matrix is
4	4	5
0	0	9
1	0	15
1	2	2
2	1	4
3	3	2
*/


