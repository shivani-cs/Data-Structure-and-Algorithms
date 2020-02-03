#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Index_seq
{
public:
	typedef struct index1
	{
		int id,pos;
	}I1;
	I1 ind;
	typedef struct master
	{
		int id;
		char name[10];
		float sal;
	}m1;
	m1 mast;
	Index_seq()
	{
		strcpy(mast.name," ");
		mast.id=-1;
		mast.sal=-1;
		ind.id=-1;
		ind.pos=-1;
	}
	
	void create();
	void display();
	int search();
	void update();
	void delete1();
	void append();
};

void Index_seq::create()
{
	int ans;
	fstream seq1;
	fstream  ind1;
	seq1.open("master.txt",ios::in | ios::out | ios::binary);
	ind1.open("index.txt",ios::in | ios::out | ios::binary);
	int i=0;
	do
	{
		cout<<"\nEnter id,name,salary: ";
		cin>>mast.id>>mast.name>>mast.sal;
		seq1.write((char *)&mast,sizeof(mast));
		ind.id=mast.id;
		ind.pos=i;
		ind1.write((char *)&ind,sizeof(ind));
		i++;
		cout<<"\nDo you want to continue then press 1: ";
		cin>>ans;
	}while(ans==1);
	
	seq1.close();
	ind1.close();
}

void Index_seq::display()
{
	fstream seq1;
	fstream ind1;
	int offset;
	seq1.open("master.txt",ios::in | ios::out | ios::binary);
	ind1.open("index.txt",ios::in | ios::out | ios::binary);
	seq1.seekg(0,ios::beg);
	ind1.seekg(0,ios::beg);
	
	
	cout<<"\nFile contents are:";
	cout<<"\nID \tName\tSalary\n";	
	while(ind1.read((char *)&ind,sizeof(ind)))
	{
		offset=ind.pos*sizeof(mast);
		seq1.seekg(offset,ios::beg);
		seq1.read((char *)&mast,sizeof(mast));
		
		if(mast.id!=-1)
		{
			cout<<mast.id<<"\t"<<mast.name<<"\t"<<mast.sal<<"\n";
		}
	}
	seq1.close();
	ind1.close();
}

void Index_seq::update()
{
	fstream seq1;
	fstream ind1;
	int offset;
	seq1.open("master.txt",ios::in | ios::out | ios::binary);
	ind1.open("index.txt",ios::in | ios::out | ios::binary);
	seq1.seekg(0,ios::beg);
	int pos;
	pos=search();
	if(pos==-1)
		cout<<"\nRecord not present";
	offset=pos*(sizeof(mast));
	seq1.seekg(offset,ios::beg);
	cout<<"\nEnter new salary: ";
	cin>>mast.sal;
	seq1.write((char *)&mast,sizeof(mast));
	seq1.seekg(0,ios::beg);
	cout<<"Record updated\n";
	cout<<mast.id<<"\t"<<mast.name<<"\t"<<mast.sal<<"\n";
	seq1.close();
	ind1.close();
}


int Index_seq::search()
{

	fstream seq1;
	fstream ind1;
	int offset,id1;
	seq1.open("master.txt",ios::in | ios::out | ios::binary);
	ind1.open("index.txt",ios::in | ios::out | ios::binary);
	cout<<"\nEnter emp_ID which you want to search: ";
	cin>>id1;
	seq1.seekg(0,ios::beg);
	int pos=-1;
	int i=0;
	while(seq1.read((char *)&mast,sizeof(mast)))
	{
		if(id1==mast.id)
		{
			pos=i;
			cout<<"\nRecord found\n";
			cout<<mast.id<<"\t"<<mast.name<<"\t"<<mast.sal;
			break;
		}
		i++;
		
	}
	return pos;
	seq1.close();
	ind1.close();
}

void Index_seq::delete1()
{
	fstream seq1;
	fstream ind1;
	int offset,id1;
	seq1.open("master.txt",ios::in | ios::out | ios::binary);
	ind1.open("index.txt",ios::in | ios::out | ios::binary);
	seq1.seekg(0,ios::beg);
	int pos;
	pos=search();
	if(pos==-1)
		cout<<"\nRecord not present";
	offset=pos*(sizeof(mast));
	seq1.seekg(offset,ios::beg);
	
	mast.id=-1;
	strcpy(mast.name," ");
	mast.sal=0.0;
	
	
	seq1.write((char *)&mast,sizeof(mast));
	seq1.seekg(0,ios::beg);	
	seq1.close();
	ind1.close();
		
}

void Index_seq::append()
{
	int pos,offset;
	fstream seq1;
	fstream  ind1;
	seq1.open("master.txt",ios::in | ios::out | ios::binary);
	ind1.open("index.txt",ios::in | ios::out | ios::binary);
	int i=0;
	cout<<"\nEnter id,name,salary";
	cin>>mast.id>>mast.name>>mast.sal;
	
	while(seq1.read((char *)&mast,sizeof(mast)))
		i++;
	pos=i;
	offset=pos*(sizeof(mast));
	seq1.write((char *)&mast,sizeof(mast));
	ind.id=mast.id;
	ind.pos=i;
	ind1.write((char *)&ind,sizeof(ind));	
	seq1.close();
	ind1.close();
}	
		
int main()
{
	Index_seq i1;
	int ch,ans;
	do
	{
		cout<<"\nFILE HANDLING\nEnter your choice:\n 1.Enter record\n 2.Display records \n 3.Search record \n 4.Update record \n 5.Delete record \n 6.Append record: ";
		cin>>ch;
	
		switch(ch)
		{
			case 1:
				i1.create();
				break;
			case 2:
				i1.display();
				break;
			case 3:
				i1.search();
				break;
			/*case 4:
				i1.update();
				break;
			case 5:
				i1.delete1();
				break;*/
			case 6 :
				i1.append();
				break;
			case 7 :
				exit(0);
		}
		cout<<"\nDo you want to go to main menu: ";
		cin>>ans;
	}while(ans==1)	;
	return 0;
}

/*OUTPUT

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 1

Enter id,name,salary: 1 a 1000

Do you want to continue then press 1: 1

Enter id,name,salary: 2 b 2000

Do you want to continue then press 1: 1

Enter id,name,salary: 3 c 3000

Do you want to continue then press 1: 1

Enter id,name,salary: 4 d 4000

Do you want to continue then press 1: 1

Enter id,name,salary: 5 e 5000

Do you want to continue then press 1: 0

Do you want to go to main menu: 1

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 2

File contents are:
ID 	Name	Salary
1	a	1000
2	b	2000
3	c	3000
4	d	4000
5	e	5000

Do you want to go to main menu: 1

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 3

Enter emp_ID which you want to search: 4

Record found
4	d	4000
Do you want to go to main menu: 1

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 3

Enter emp_ID which you want to search: 10

Do you want to go to main menu: 1

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 4

Enter emp_ID which you want to search: 2

Record found
2	b	2000
Enter new salary: 2500
Record updated
2	b	2500

Do you want to go to main menu: 1

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 5

Enter emp_ID which you want to search: 3

Record found
3	c	3000
Do you want to go to main menu: 1

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 2

File contents are:
ID 	Name	Salary
1	a	1000
2	b	2500
4	d	4000
5	e	5000

Do you want to go to main menu: 1

FILE HANDLING
Enter your choice:
 1.Enter record
 2.Display records 
 3.Search record 
 4.Update record 
 5.Delete record 
 6.Append record: 5 

Enter emp_ID which you want to search: 10

Record not present
Do you want to go to main menu: 1
*/




