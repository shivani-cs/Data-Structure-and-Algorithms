#include<iostream>
using namespace std;
template<class t>
class node
{
	public:
	t x;
	node<t> *next;
	node()
	{
		next=NULL;
	}
};
template<class t>
class stack
{
	public:
	int count;
	node<t> *top;
	stack()
	{
		count=0;
		top=NULL;
	}
	int stackempty()
	{
		if(top==NULL)
			return 1;
		else
			return 0;
	}
	int stackfull()
	{
		node<t> *temp1;
		temp1=new node<t>;
		if(temp1==NULL)
		{
			delete temp1;
			return 1;
		}
		else
		{
			delete temp1;
			return 0;
		}
	}
	void push(t x)
	{
		if(stackfull())
			cout<<"Failed";
		else
		{
			node<t> *temp;
			temp=new node<t>;
			temp->x=x;
			count=count+1;
			temp->next=top;
			top=temp;
		}
	}
	t pop()
	{
		t temp;
		node<t> *temp1;
		temp1=top;
		top=top->next;
		temp=temp1->x;
		delete temp1;
		return temp;
	}
	void display()
	{
		node<t> *pnew=top;
		while(pnew!=NULL)
		{
			cout<<pnew->x;
			pnew=pnew->next;
		}
	}
	t stacktop()
	{
		if(stackempty())
			return 0;
		t temp1;
		temp1=top->x;
		return temp1;
	}
};


/*
int main()
{
  char x;
  stack <char> s1;
  int ch,ch1;

  do
  {
     	cout<<"Enter choice ";
  	cin>>ch;
  	switch(ch)
  	{
   	 	case 1:s1.push(x);
	   		//s1.display();
	   		break;
    		case 2:s1.pop();
	  		// s1.display();
	  		break;
   		case 3:s1.stacktop();
	  		break;
   		case 4:s1.display();
	 	 	break;
  	}
	cout<<"Enter 1 to cont";
	cin>>ch1;
	}while(ch1==1);
	return 0;
}*/


