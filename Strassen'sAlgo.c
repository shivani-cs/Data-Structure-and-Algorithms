#include<stdio.h>
int num;
void strassen(int a[][num],int b[][num],int c[][num],int size)
{
	int p1[size/2][size/2],p2[size/2][size/2],p3[size/2][size/2],p4[size/2][size/2],p5[size/2][size/2],p6[size/2][size/2],p7[size/2][size/2],temp1[size/2][size/2],temp2[size/2][size/2];
	int q1,q2,q3,q4,q5,q6,q7,i,j;

	if(size>=2)
	{
		//p1
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp1[i][j] = a[i][j]+a[i+size/2][j+size/2];
			}
		}
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp2[i][j] = b[i][j]+b[i+size/2][j+size/2];
			}
		}
		num = size/2;
		strassen(temp1,temp2,p1,size/2);	
		//p2		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp1[i][j] = a[i+size/2][j]+a[i+size/2][j+size/2];
			}
		}
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp2[i][j] = b[i][j];
			}
		}
		num = size/2;
		strassen(temp1,temp2,p2,size/2);	
		//p3		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp1[i][j] = a[i][j];
			}
		}
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp2[i][j] = b[i][j+size/2]-b[i+size/2][j+size/2];
			}
		}
		num = size/2;
		strassen(temp1,temp2,p3,size/2);	
		//p4		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp1[i][j] = a[i+size/2][j+size/2];
			}
		}
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp2[i][j] = b[i+size/2][j]-b[i][j];
			}
		}
		num = size/2;
		strassen(temp1,temp2,p4,size/2);	
		//p5		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp1[i][j] = a[i][j]+a[i][j+size/2];
			}
		}
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp2[i][j] = b[i+size/2][j+size/2];
			}
		}
		num = size/2;
		strassen(temp1,temp2,p5,size/2);	
		//p6		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp1[i][j] = a[i+size/2][j]-a[i][j];
			}
		}
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp2[i][j] = b[i][j]+b[i][j+size/2];
			}
		}
		num = size/2;
		strassen(temp1,temp2,p6,size/2);	
		//p7		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp1[i][j] = a[i][j+size/2]-a[i+size/2][j+size/2];
			}
		}
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				temp2[i][j] = b[i+size/2][j]+b[i+size/2][j+size/2];
			}
		}
		num = size/2;
		strassen(temp1,temp2,p7,size/2);
		//c11		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				c[i][j] = p1[i][j]+p4[i][j]-p5[i][j]+p7[i][j];
			}
		}
		//c12		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				c[i][j+size/2] = p3[i][j]+p5[i][j];
			}
		}
		//c21		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				c[i+size/2][j] = p2[i][j]+p4[i][j];
			}
		}
		//c22		
		for(i=0;i<size/2;i++)
		{
			for(j=0;j<size/2;j++)
			{
				c[i+size/2][j+size/2] = p1[i][j]+p3[i][j]-p2[i][j]+p6[i][j];
			}
		}
	}
	else if(size==1)
		{
			c[0][0]=a[0][0]*b[0][0];
		}
}

int padding(int num)
{
	int original_num=num,lower_power=0,i,actual_num=1;
	if(num==1)
		return 1;
	while(num>1)
	{
		lower_power++;
		num/=2;
	}
	for(i=0;i<lower_power;i++)
	{
		actual_num*=2;
	}
	if(actual_num==original_num)
		return original_num;
	else
		return actual_num*2;

}

int main()
{
	int i,j,temp;
	printf("Enter the size of the n*n matrix");
	scanf("%d",&num);
	temp=num;
	if(num<=0)
		return 0;
	num=padding(num);
	int a[num][num],b[num][num],c[num][num];
	printf("Enter the Matrix A: ");
	for(i=0;i<temp;i++)
	{
		for(j=0;j<temp;j++)
		{
			scanf("%d",&a[i][j]);
		}
		for(j=temp;j<num;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=temp;i<num;i++)
		for(j=0;j<num;j++)
			a[i][j]=0;
	
	printf("Enter the Matrix B: ");
	for(i=0;i<temp;i++)
	{
		for(j=0;j<temp;j++)
		{
			scanf("%d",&b[i][j]);
		}
		for(j=temp;j<num;j++)
		{
			b[i][j]=0;
		}
	}
	for(i=temp;i<num;i++)
		for(j=0;j<num;j++)
			b[i][j]=0;

	printf("Matrix A: \n");
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	printf("Matrix B: \n");
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	strassen(a,b,c,num);
	
	printf("\nMatrix C: \n");
	for(i=0;i<temp;i++)
	{
		for(j=0;j<temp;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*OUTPUT
Enter the size of the n*n matrix4
Enter the Matrix A: 2 4 3 4
1 1 2 6
2 4 1 2
3 2 3 1
Enter the Matrix B: 4 2 4 6 
1 1 1 9
3 6 5 2
6 2 2 3
Matrix A: 
2 4 3 4 
1 1 2 6 
2 4 1 2 
3 2 3 1 
Matrix B: 
4 2 4 6 
1 1 1 9 
3 6 5 2 
6 2 2 3 

Matrix C: 
45 34 35 66 
47 27 27 37 
27 18 21 56 
29 28 31 45 
*/
