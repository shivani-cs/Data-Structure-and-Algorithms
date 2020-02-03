#include <iostream>
using namespace std;

class table
{	
	public:
	int a[20][2];
	int size;
	void create();
	void chain_withoutr();
	void chain_withr();
	void display();
	void search();
};

void table::create()
{	
	int i,j;
	cout<<"Enter the no of elements\t";
	cin>>size;
	for(i=0;i<size;i++)
	{
		a[i][0]=-1;
		a[i][1]=999;
	}
}
		
void table::chain_withoutr()
{	
	int no,index,i,j,z;
	cout<<"Enter the element\t";
	cin>>no;
	index=no%size;
	if(a[index][0]==-1)
		a[index][0]=no;
	else
	{	
		for(i=index;i<=size;i=(i+1)%size)
		{	
			if(a[i][0]==-1)
			{
				a[i][0]=no;
				break;
			}
		}
		for(j=index;j<=size;j=(j+1)%size)
		{
		    if(a[j][1]!=999 && a[j][0]%size==no%size)
		    {
		        z=a[j][1];
		        if(a[j+1][1]!=999)
		            continue;
		        a[z][1]=i;
		        	break;
		    }
		    else if(a[j][1]==999 && a[j][0]%size==no%size)
		    {
		        a[j][1]=i;
		        break;
		    }
		    else
		     break;
		     
		}
	}
}

void table::search()
{
	int key,index,j,flag=0;
	cout<<"\nEnter the element you want to search-";
	cin>>key;
	index=key%size;
	while(flag==0)
	{
		if(a[index][0]==key)
		{
			cout<<"\nKey is found at position "<<index;
			flag=1;
		}
		else
		{
			if(a[index][1]==999)
			{
				cout<<"\nKey is not present.";
				return;
			}
			else
			{
				index=a[index][1];
			}

		}
	}
}

void table::display()
{
	int i,j;
	cout<<"The table is\n";
	for(i=0;i<size;i++)
		
	{
		cout<<"a["<<i<<"]"<<"[0]"<<"="<<a[i][0]<<"\t"<<"a["<<i<<"]"<<"[1]"<<"="<<a[i][1]<<"\n";
	}
}

void table::chain_withr()
{
	int j,i,index,key,temp,link;
	cout<<"\nEnter the element-";
	cin>>key;
	index=key%size;
	if(a[index][0]==-1)
	{
		a[index][0]=key;
	}
	else if(a[index][0]%size==key%size)
	{
		if(a[index][1]==999)
		{
			for(j=index+1;j<size;(j+1)%size)
			{
				if(a[j][0]==-1)
				{
					a[j][0]=key;
					a[index][1]=j;
					break;
				}
			}
		}
		else
		{
			while(a[index][1]!=999)
			{
				index=a[index][1];
			}
			for(j=index+1;j<size;(j+1)%size)
			{
				if(a[j][0]==-1)
				{
					a[j][0]=key;
					a[index][1]=j;
					break;
				}
			}
		}
	}
	else if()
	{
		temp=a[index][0];
		a[index][0]=key;
		key=temp;
		if(a[index][1]!=999)
		{
			link=a[index][1];
			a[index][1]=999;
		}
		for(i=index+1;i<size;(i+1)%size)
		{
			if(a[i][0]==-1)
			{
				a[i][0]=key;
				break;
			}
		}
		j=0;
		while(j<size)
		{
			if(a[j][1]==index)
			{
				a[j][1]==i;
			}
		}
	}
}
int main()
{
	table t;
	int ch,ans,i,ch1,ch2;
	do
	{
	cout<<"Enter\n1-chaining without replacement\n2-chaining with replacement\n";
	cout<<"Enter your choice\t";
	cin>>ch;
	switch(ch)
	{
		case 1: 
			do
			{
			cout<<"Enter\n1-Insert element\n2-display\n3-searching\n";
			cout<<"Enter your choice\t";
			cin>>ch1;
			switch(ch1)
			{
				case 1:t.create();
						for(i=0;i<t.size;i++)
						{	
							t.chain_withoutr();
						}
						break;

				case 2: t.display();
						break;

				case 3: t.search();
						break;
			}
				cout<<"\nEnter 1 to continue\t";
				cin>>ans;
			}while(ans==1);
			break;
		case 2: 
			do
			{
			cout<<"Enter\n1-Insert element\n2-display\n3-searching\n";
			cout<<"Enter your choice\t";
			cin>>ch1;
			switch(ch1)
			{
				case 1:t.create();
						for(i=0;i<t.size;i++)
						{	
							t.chain_withr();
						}
						break;

				case 2: t.display();
						break;

				case 3: t.search();
						break;
			}
				cout<<"\nEnter 1 to continue\t";
				cin>>ans;
			}while(ans==1);
			break;
	}
		cout<<"\nEnter 1 to continue\t";
		cin>>ans;
	}while(ans==1);
	return 0;
}
	
