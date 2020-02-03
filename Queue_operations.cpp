#include<iostream>
using namespace std;
#include<string.h>
int f=-1;
int r=-1;
#define SIZE 2
class queue
{
	int roll_no;
	char s_name[20];
	float marks;
	public:
	void enque(int no,char n[20],float mark);
	void deque();
	int queue_full();
	int queue_empty();
	void overflow();
	void underflow();
	void display();

};
int queue::queue_full()
{
	if(f==(r+1)%SIZE)
		return 1;
	else
		return 0;
}
int queue::queue_empty()
{
	if(f==-1)
		return 1;
	else
		return 0;
}
void queue::overflow()
{
	if(queue_full())
		cout<<"Overflow has occured.";
	else
		cout<<"Overflow has not occured.";
}
void queue::underflow()
{
	if(queue_empty())
		cout<<"Underflow has occured.";
	else
		cout<<"Underflow has not occured.";
}

void queue::enque(int no,char n[20],float mark)
{
    roll_no=no;
    strcpy(s_name,n);
    marks=mark;
}
void queue::deque()
{
	int x;
	char y[20];
	float z;
	x=roll_no;
	strcpy(y,s_name);
	z=marks;
	cout<<"Deleted record-";
	cout<<x<<"\n"<<y<<"\n"<<z;
}
void queue::display()
{
	cout<<roll_no<<s_name<<marks<<"\n";
}

int main()
{
	queue q[SIZE];
	int no,ch,i;
	char n[20];
	float mark;
	
	do
	{
	cout<<"1-Insert record\n2-Delete record\n3-Overflow\n4-Underflow\n5:display\n6-Exit";
	cout<<"\nPrint your choice-";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"Enter roll no, name, marks-";
			cin>>no>>n>>mark;
			if(q[r].queue_full())
			{
				cout<<"Queue is full.";
					
			}
			else if(f==-1)
			{
				f=(f+1)%SIZE;
				r=(r+1)%SIZE;
				q[r].enque(no,n,mark);
			}
			else
			{
				r=(r+1)%SIZE;
				q[r].enque(no,n,mark);
			}
			break;
		case 2:  if(q[f].queue_empty())
			{
				cout<<"Queue is empty.";
			}
			else if(f==r)
			{
				q[f].deque();
				f=-1;
				r=-1;
			}
			else
			{
				q[f].deque();
				f=(f+1)%SIZE;
			}
			break;
		case 3:q[r].overflow();
			break;
		case 4:q[f].underflow();
			break;
	
		case 5: i=f;
			while(i!=r)
			{
				q[i].display();
				i=(i+1)%SIZE;
			}
			q[r].display();
			break;
		case 6:return 1;
	}
	}while(ch>0&&ch<7);
}
/*
output:
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-1
Enter roll no, name, marks-10 harsha 78
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-1
Enter roll no, name, marks-11 jyo 90
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-1
Enter roll no, name, marks-12 mansi 89
Queue is full.
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-5
10 harsha 78
11 jyo 90
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-3
Overflow has occured.
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-2
Deleted record-10 harsha 78
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-2
Deleted record-11 jyo 90
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
Print your choice-4
Underflow has occured.
1-Insert record
2-Delete record
3-Overflow
4-Underflow
5:display
*/

