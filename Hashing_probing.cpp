#include<iostream>
using namespace std;
class table
{
	int a[15];
	public:
	int size;
	void create()
	{
		int i;
		cout<<"\nEnter the no. of elements-";
	        cin>>size;
		for(i=0;i<15;i++)
		{
			a[i]=-1;
		}
	}
	void prob();
	void probr();
	void prob_search();

};

void table::prob()
{
	int j,index,key;
	cout<<"\nEnter the element-";
	cin>>key;
	index=key%size;
	if(a[index]==-1)
	{
		a[index]=key;
	}
	else
	{
		j=index+1;
		while(j<=size)
		{
			if(a[j]==-1)
			{
				a[j]=key;
				return;
			}
			j++;
			j=j%size;
		}
	}
}

void table::prob_search()
{
	int key,index,j;
	cout<<"\nEnter the element you want to search-";
	cin>>key;
	index=key%size;
	if(a[index]==key)
	{
		cout<<"\nKey is found at position "<<index%size;
	}
	else
	{
		j=index+1;
		while(j<=size)
		{
			if(a[j]==key)
			{
				cout<<"\nKey is found at position "<<j%size;
				return;
			}
			j++;
			j=j%size;
		}
	}
}

void table::probr()
{
	int j,index,key,temp;
	cout<<"\nEnter the element-";
	cin>>key;
	index=key%size;
	if(a[index]==-1)
	{
		a[index]=key;
	}
	else if(a[index]%size==key%size)
	{
		j=index;
		while(j<=size)
		{
			if(a[j]==-1)
			{
				a[j]=key;
				return;
			}
			else
				j++;
			j=j%size;
		}
	}
	else
	{
		temp=a[index];
		a[index]=key;
		key=temp;
		j=index+1;
		while(j<=size)
		{
			if(a[j]==-1)
			{
				a[j]=key;
				return;
			}
			else
				j++;
			j=j%size;
		}
	}
}



int main()
{
	table t;
	int ch,i=0,flag,ans;
	do
	{
	cout<<"\n1-Probing without replacement\n2-Probing with replacement\n3-Exit";
	cout<<"\nPrint your choice-";
	cin>>ch;
	switch(ch)
	{
		case 1: t.create();
			do
			{
			cout<<"\n1-Insert elements\n2-Search element";
			cout<<"\nPrint your choice-";
			cin>>flag;
			if(flag==1)
			{
				for(i=0;i<t.size;i++)
					t.prob();
			}
			else
				t.prob_search();
			cout<<"\nPress 1 to continue probing without replacement...";
			cin>>ans;
			}while(ans==1);
			break;
		case 2: t.create();
			do
			{
			cout<<"\n1-Insert elements\n2-Search element";
			cout<<"\nPrint your choice-";
			cin>>flag;
			if(flag==1)
			{
				for(i=0;i<t.size;i++)
					t.probr();
			}
			else
				t.prob_search();
			cout<<"\nPress 1 to continue probing without replacement...";
			cin>>ans;
			}while(ans==1);
			break;
		case 3: return 0;
	}
	}while(ch>0&&ch<4);
	return 0;
}

/*
OUTPUT-
1-Probing without replacement
2-Probing with replacement
3-Exit
Print your choice-1

Enter the no. of elements-5

1-Insert elements
2-Search element
Print your choice-1

Enter the element-32

Enter the element-41

Enter the element-60

Enter the element-22

Enter the element-43

Press 1 to continue probing without replacement...1

1-Insert elements
2-Search element
Print your choice-2

Enter the element you want to search-43

Key is found at position 4
Press 1 to continue probing without replacement...1

1-Insert elements
2-Search element
Print your choice-2

Enter the element you want to search-41

Key is found at position 1
Press 1 to continue probing without replacement...1

1-Insert elements
2-Search element
Print your choice-2

Enter the element you want to search-32

Key is found at position 2
Press 1 to continue probing without replacement...0

1-Probing without replacement
2-Probing with replacement
3-Exit
Print your choice-2

Enter the no. of elements-5

1-Insert elements
2-Search element
Print your choice-1

Enter the element-32

Enter the element-41

Enter the element-60

Enter the element-22

Enter the element-43

Press 1 to continue probing without replacement...1

1-Insert elements
2-Search element
Print your choice-2

Enter the element you want to search-22

Key is found at position 4
Press 1 to continue probing without replacement...1

1-Insert elements
2-Search element
Print your choice-2

Enter the element you want to search-43

Key is found at position 3
Press 1 to continue probing without replacement...1

1-Insert elements
2-Search element
Print your choice-2

Enter the element you want to search-60

Key is found at position 0
Press 1 to continue probing without replacement...0

1-Probing without replacement
2-Probing with replacement
3-Exit
Print your choice-3
*/
