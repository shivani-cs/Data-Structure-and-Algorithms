#include<iostream>
#include<stdlib.h>
using namespace std;
class heap
{
	public:
	void sort(int a[20],int last)
	{
		int i,j,temp;
		for(i=1;i<=last;i++)
		{
			reheapup(a,i);
			j=last;
		}
		while(j>0)
		{
			temp=a[0];
			a[0]=a[j];
			a[j]=temp;
			j--;
			reheapdown(a,0,j);
		}
	}
	void reheapup(int a[20],int newnode)
	{
		int parent,temp;
		if(newnode!=0)
		{
			parent=(newnode-1)/2;
			if(a[newnode] > a [parent])
			{
				temp=a[parent];
				a[parent]=a[newnode];
				a[newnode]=temp;
				reheapup(a,parent);
			}
		}
	}
	void reheapdown(int a[20],int root,int last)
	{
		int temp,leftkey,rightkey,largechildkey;
		int largechildindex;
		if((root*2+1)<=last)
		{
			leftkey=a[root*2+1];
			if((root*2+2)<=last)
			{
				rightkey=a[root*2+2];
			}
			else
			{
				rightkey=-1;
			}
			if(leftkey>rightkey)
			{
				largechildkey=leftkey;
				largechildindex=root*2+1;
			}
			else
			{
				largechildkey=rightkey;
				largechildindex=root*2+2;
			}
			if(a[root] < a[largechildindex])
			{
				temp=a[root];
				a[root]=a[largechildindex];
				a[largechildindex]=temp;
				reheapdown(a,largechildindex,last);
			}
		}
	}
	void display(int a[20],int n)
	{
		int i;
		cout<<"Heap sort output is"<<"\n";
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<"\n";
		}
	}
};
int main()
{
	int a[20],n,i;
	heap h;
	cout<<"Enter no of nodes";
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"Enter node\t"<<i+1<<endl;
        cin>>a[i];
    }
 	h.sort(a,n-1);
 	h.display(a,n);
	return 0 ;
}

/*OUTPUT
Enter no of nodes5
Enter node      1

12
Enter node      2

33
Enter node      3

44
Enter node      4
4
Enter node      5
2
Heap sort output is
2
4
12
33
44

Process returned 0 (0x0)   execution time : 20.379 s
Press any key to continue.
*/
