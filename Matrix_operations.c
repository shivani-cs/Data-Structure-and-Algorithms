/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title- 2. Represent matrix using two dimensional arrays and perform following operations:   
  	 i) Addition using pointers ii) multiplication without pointers   iii) transpose using pointers
*/

#include<stdio.h>
void add(int (*a)[10],int (*b)[10],int (*c)[10],int r1,int r2);
void multiply(int a[10][10],int b[10][10],int r1,int r2,int c1,int c2);
void transpose(int (*a)[10],int (*c)[10],int r1,int c1);
void main()
{
 int d[10][10],e[10][10],R1,R2,C1,C2,ch,i,j,f[10][10],ans;
 printf("Enter 1 for addition\nEnter 2 for multiplication\nEnter 3 for transpose\n");
 do
 {
 	printf("Enter your choice\n");
 	scanf("%d",&ch);
 	switch(ch)
 	{
	        case 1:printf("Enter no of rows and columns for first and second matrix\n");
          	       scanf("%d%d",&R1,&C1);
                       printf("Enter the elements of first matrix\n");
                       for(i=0;i<R1;i++)
                       {
                            for(j=0;j<C1;j++)
                            {
                                  scanf("%d",&d[i][j]);					//read first matrix;
                            }
                       }
                       printf("matrix d is\n");
                       for(i=0;i<R1;i++)
                       {
                            for(j=0;j<C1;j++)
                            {
                                  printf("\t%d",d[i][j]);				//print first matrix;
                            }
                            printf("\n");
                       }
                       printf("Enter the elements of second matrix\n");
                       for(i=0;i<R1;i++)
                       {
                            for(j=0;j<C1;j++)
                            {
                                  scanf("%d",&e[i][j]);					//read second matrix;
                            }
                       }
                       printf("matrix e is\n");
                       for(i=0;i<R1;i++)
                       {
                             for(j=0;j<C1;j++)
                             {
                                   printf("\t%d",e[i][j]);				//print second matrix;
                             }
                             printf("\n");
                       }
                       add(&d,&e,&f,R1,C1);						//call function add;
                       break;
                case 2:printf("Enter no of rows and columns for first matrix\n");
                       scanf("%d%d",&R1,&C1);
                       printf("Enter no rows and columns for second matrix\n");
                       scanf("%d%d",&R2,&C2);
                       if(C1==R2)
                       {
                       		printf("Enter the elements of first matrix\n");
                       		for(i=0;i<R1;i++)
                	        {
                     			for(j=0;j<C1;j++)
                     			{
                           			scanf("%d",&d[i][j]);
                     			}
                		}
               			printf("matrix d is\n");
               			for(i=0;i<R1;i++)
               			{
                    			for(j=0;j<C1;j++)
                    			{
                            			printf("\t%d",d[i][j]);
                    			}
                    			printf("\n");
               			}
              			printf("Enter the elements of second matrix\n");
               			for(i=0;i<R2;i++)
               			{
                   			for(j=0;j<C2;j++)
                   			{
                   				scanf("%d",&e[i][j]);
                   			}
               			}
               			printf("matrix e is\n");
               			for(i=0;i<R2;i++)
               			{
                   			for(j=0;j<C2;j++)
                   			{
                   				printf("\t%d",e[i][j]);
                   			}
                   				printf("\n");
               			}
               			multiply(d,e,R1,R2,C1,C2);				//call function multiply;
                	}
                	else
                	printf("Multiplication is not possible");
                	break;
                case 3: printf("Enter no of rows and columns for matrix\n");
                        scanf("%d%d",&R1,&C1);
                        printf("Enter the elements of matrix\n");
                        for(i=0;i<R1;i++)
                        {
                        	for(j=0;j<C1;j++)
                        	{
                           		scanf("%d",&d[i][j]);
                        	}
                     	}
                     	printf("matrix d is\n");
                     	for(i=0;i<R1;i++)
                     	{
                         	for(j=0;j<C1;j++)
                         	{
                             		printf("\t%d",d[i][j]);
                         	}
                         	printf("\n");
                     	}
                     	transpose(&d,&f,R1,C1);						//call function transpose;
	}
		printf("Enter 1 to continue\t");
		scanf("%d",&ans);
 }
 while(ans==1);
}
void add(int (*a)[10],int (*b)[10],int (*c)[10],int r1,int c1)	 /* this function performs addition of two matrices 												   using pointers */
{ 
    int i,j;
    printf("matrix c is\n");
    for(i=0;i<r1;i++)
    {
         for(j=0;j<c1;j++)
         {
              *(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
	 }
         printf("Addtion is\n");
	 for(i=0;i<r1;i++)
   	 {
         	for(j=0;j<c1;j++)
         	{
            		printf("\t%d",c[i][j]);
         	}
        	 printf("\n");
    	 }
}
void multiply(int a[10][10],int b[10][10],int r1,int r2,int c1,int c2)			/* this function performs multiplication of two 											   matrices without using pointer */
{ 
       int i,j,k,c[10][10];
       for(i=0;i<r1;i++)
       {
             for(j=0;j<c2;j++)
              {  
                     c[i][j]=0;
                     for(k=0;k<c1;k++)
                     {
                      	    c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
		                 }
	      }
	}  
        printf("Multiplication  is\n");
	for(i=0;i<r1;i++)
        {
              for(j=0;j<c2;j++)
              {
                     printf("\t%d",c[i][j]);
              }
              printf("\n");
	}
} 
void transpose(int (*a)[10],int (*c)[10],int r1,int c1)					/* this function performs tranpose operation on a 												   matrices using pointers */
{
     int i,j;
     printf("matrix c is\n"); 
     for(i=0;i<r1;i++)
     {
          for(j=0;j<c1;j++)
          {
                *(*(c+j)+i)=*(*(a+i)+j);
          }
     }
     printf("Transpose is\n");
     for(i=0;i<c1;i++)
     {
          for(j=0;j<r1;j++)
          {
               printf("\t%d",c[i][j]);
          }
          printf("\n");
     }
}
  
/* OUTPUT  
Enter 1 for addition
Enter 2 for multiplication
Enter 3 for transpose
Enter your choice
1
Enter no of rows and columns for first and second matrix
3
3
Enter the elements of first matrix
1 2 3 4 5 6 7 8 9 
matrix d is
	1	2	3
	4	5	6
	7	8	9
Enter the elements of second matrix
2 3 4 5 6 7 8 9 0 
matrix e is
	2	3	4
	5	6	7
	8	9	0
Addtion is
	3	5	7
	9	11	13
	15	17	9
Enter 1 to continue	1 
Enter your choice
2
Enter no of rows and columns for first matrix
3
3
Enter no rows and columns for second matrix
3
3
Enter the elements of first matrix
1 2 3 4 5 6 7 8 9 
matrix d is
	1	2	3
	4	5	6
	7	8	9
Enter the elements of second matrix
2 3 4 5 6 7 8 9 0
matrix e is
	2	3	4
	5	6	7
	8	9	0
Multiplication  is
	36	42	18
	81	96	51
	126	150	84
Enter 1 to continue	1
Enter your choice
3
Enter no of rows and columns for matrix
3
3
Enter the elements of matrix
1 2 3 4 5 6 7 8 9 
matrix d is
	1	2	3
	4	5	6
	7	8	9
matrix c is
Transpose is
	1	4	7
	2	5	8
	3	6	9
Enter 1 to continue	
*/        
  
  
        
         

 
