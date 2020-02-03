#include<iostream>
#include<string.h>
using namespace std;
class node
{   
    public:
	char name[20];
	int age;
	int pri;
	node *next;
	node()
	{
		next=NULL;
	}
};

class queue
{
	node *f;
	node *r;
	public:
	queue()
	{
		f=NULL;
		r=NULL;
	}
	int empty();
	int full();
	void enque(char n[20],int a,int p);
	void deque();
	void display();
	void quefront();
	void querear();
};

int queue::empty()
{
	if(f==NULL)
		return 1;
	else
		return 0;
}

int queue::full()
{
	node *pnew=new node;
	if(pnew==NULL)
	{
		delete pnew;
		return 1;
	}
	else
	{
		delete pnew;
		return 0;
	}
}

void queue::enque(char n[20],int a,int p)
{
	if(full())
	{
		cout<<"\nNO PLACE";
		return;
	}
	node *pnew= new node;
	pnew->age=a;
	pnew->pri=p;
	strcpy(pnew->name,n);
	if(f==NULL)
		f=pnew;
	else
		r->next=pnew;
	r=pnew;
}

void queue::deque()
{
	if(empty())
	{
		cout<<"\nNO PATIENTS.";
		return;
	}
	node *dltptr=new node;
	dltptr=f;
	if(f==r)
	{
		r=NULL;
	}
	f=f->next;
	cout<<"\nDischarged patient-"<<dltptr->name<<dltptr->age;
	delete dltptr;
}

void queue::querear()
{
	if(empty())
		return;
	else
	{	
		cout<<"Last served patient details are\n"<<r->name<<" "<<r->age;
	}
}

void queue::quefront()
{
	if(empty())
		return;
	else
	{	
		cout<<"current served patient details are\n"<<f->name<<" "<<f->age;
	}
}
		
void queue::display()
{
	if(empty())
	{
		cout<<"\nNO PATIENTS";
		return;
	}
	node *ptr;
	ptr=f;
	cout<<"\nPriority-"<<ptr->pri<<"\nPatient detail-";
	while(ptr!=NULL)
	{
		cout<<"\nname-"<<ptr->name<<"\n"<<"age-"<<ptr->age;
		ptr=ptr->next;
	}
}

int main()
{
	queue q[3];
	int ch,p,a;
	char n[20];
	do
	{
	cout<<"\n1-Insert detail"<<"\n"<<"2-Delete detail"<<"\n"<<"3-Display"<<"\n"<<"4-last served patient"<<"\n"<<"5-current served patient"<<"\n"<<"6-Exit";
	cout<<"\nEnter your choice-";
	cin>>ch;
	switch(ch)
	{
	   case 1:cout<<"0-Serious"<<" "<<"1-Medium"<<" "<<"2-General";
		  cout<<"\nEnter the priority of patient-";
		  cin>>p;
		  cout<<"\nEnter patient detail-";
		  cout<<"\nName-";
		  cin>>n;
		  cout<<"\nAge-";
		  cin>>a;
		  q[p].enque(n,a,p);
		  break;
	   case 2:cout<<"0-Serious"<<" "<<"1-Medium"<<" "<<"2-General";
		  cout<<"\nEnter the priority of patient-";
		  cin>>p;
		  q[p].deque();
		  break;
	   case 3:cout<<"0-Serious"<<" "<<"1-Medium"<<" "<<"2-General";
		  cout<<"\nEnter the priority of patient-";
		  cin>>p;
		  q[p].display();
		  break;

	   case 4:cout<<"0-Serious"<<" "<<"1-Medium"<<" "<<"2-General";
		  cout<<"\nEnter the priority of patient-";
		  cin>>p;
		  q[p].querear();
		  break;

	   case 5:cout<<"0-Serious"<<" "<<"1-Medium"<<" "<<"2-General";
		  cout<<"\nEnter the priority of patient-";
		  cin>>p;
		  q[p].quefront();
		  break;

	   case 6: return 1;
	   default:cout<<"Choice is wrong.";
			break;
	}
	}while(ch>0&&ch<7);
}

/*output:
ubuntu04-2@ubuntu042-ThinkCentre-M60e:~$ cd Desktop
ubuntu04-2@ubuntu042-ThinkCentre-M60e:~/Desktop$ g++ p.cpp
ubuntu04-2@ubuntu042-ThinkCentre-M60e:~/Desktop$ ./a.out

1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-1
0-Serious1-Medium2-General
Enter the priority of patient-0

Enter patient detail-
Name-purva

Age-78     

1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-1
0-Serious1-Medium2-General
Enter the priority of patient-1

Enter patient detail-
Name-mansi

Age-34

1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-1
0-Serious1-Medium2-General
Enter the priority of patient-2

Enter patient detail-
Name-komal

Age-67

1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-3
0-Serious1-Medium2-General
Enter the priority of patient-0

Priority-0
Patient detail-
name-purva
age-78
1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-3
0-Serious1-Medium2-General
Enter the priority of patient-1

Priority-1
Patient detail-
name-mansi
age-34
1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-3
0-Serious1-Medium2-General
Enter the priority of patient-2

Priority-2
Patient detail-
name-komal
age-67
1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-2
0-Serious1-Medium2-General
Enter the priority of patient-0

Discharged patient-purva78
1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-3
0-Serious1-Medium2-General
Enter the priority of patient-0

NO PATIENTS
1-Insert detail
2-Delete detail
3-Display
4-Exit
Enter your choice-4
*/











