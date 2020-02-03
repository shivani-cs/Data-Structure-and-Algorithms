/*
Name- Shivani Suryawanshi.
Roll no.- SEIT155
Title-  7.Implement Quick Sort recursively to sort the given list of numbers / records. 
	Display pivot position and its corresponding list in each pass.
*/

#include<stdio.h>
void quicksort(int a[10],int p,int q);
int partition(int a[10],int left,int right);
void main()
{
	int a[10],n,p,q,i;
	printf("How many elements you want to enter in array a-");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the element a[%d]:",i);
		scanf("%d",&a[i]);
	}
	p=1;
	q=n;
	quicksort(a,p,q);
	printf("\nAray is ");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}
void quicksort(int a[10],int p,int q)
{
	int j;	
	if(p>q)
	return;
	j=partition(a,p,q);
	quicksort(a,p,j-1);
	quicksort(a,j+1,q);	
}
int partition(int a[10],int left,int right)
{
	int i,j,pivot,temp;
	pivot=a[left];
	i=left;
	j=right+1;
	do
	{
		do
		{
			i++;
		}while(a[i]<pivot);
		do
		{
			j--;
		}while(a[j]>pivot);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	a[left]=a[j];
	a[j]=pivot;
	printf("\nPivot element is %d & Partition position is %d.",pivot,j);
	printf("\nAray is ");
	for(i=left;i<=right;i++)
	{
		printf("%d\t",a[i]);
	}
	return(j);
}

/*
OUTPUT-

How many elements you want to enter in array a-10
Enter the element a[1]:56
Enter the element a[2]:-90
Enter the element a[3]:80
Enter the element a[4]:78
Enter the element a[5]:234
Enter the element a[6]:654
Enter the element a[7]:432
Enter the element a[8]:12
Enter the element a[9]:0
Enter the element a[10]:-11

Pivot element is 56 & Partition position is 5.
Aray is 12	-90	-11	0	56	654	432	234	78	80	
Pivot element is 12 & Partition position is 4.
Aray is 0	-90	-11	12	
Pivot element is 0 & Partition position is 3.
Aray is -11	-90	0	
Pivot element is -11 & Partition position is 2.
Aray is -90	-11	
Pivot element is -90 & Partition position is 1.
Aray is -90	
Pivot element is 654 & Partition position is 10.
Aray is 80	432	234	78	654	
Pivot element is 80 & Partition position is 7.
Aray is 78	80	234	432	
Pivot element is 78 & Partition position is 6.
Aray is 78	
Pivot element is 234 & Partition position is 8.
Aray is 234	432	
Pivot element is 432 & Partition position is 9.
Aray is 432	
Aray is -90	-11	0	12	56	78	80	234	432	654	
*/
		
		

	
		
