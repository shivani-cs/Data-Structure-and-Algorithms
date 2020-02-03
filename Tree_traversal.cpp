#include<iostream>
using namespace std;
class tnode
{
	public:	
	char data;
	tnode *lc;
	tnode *rc;
	tnode()
	{
		lc=NULL;
		rc=NULL;
	}
};
class tree
{	
	tnode *root;
	public:
	tree()
	{
		root=NULL;
	}
	tnode *exptree(char exp[20]);
	void nrec_inorder(tnode *n);
	void nrec_preorder(tnode *n);
	void nrec_postorder(tnode *n);
	void rec_inorder(tnode *n);
	void rec_preorder(tnode *n);
	void rec_postorder(tnode *n);
};

class node
{
	public:
	tnode *temp;
	node *next;
	node()
	{
		next=NULL;
	}
};
class stack
{
	public:
	node *top;
	stack()
	{
		top=NULL;
	}
	int empty()
	{
		if(top==NULL)
			return 1;
		else
			return 0;
	}
	void push(tnode *temp)
	{
		node *pnew=new node;
		pnew->temp=temp;
		pnew->next=top;
		top=pnew;	
	}
	tnode *pop()
	{
		if(empty())
			return 0;
		else
		{		
			node *pnew;
			pnew=top;
			top=pnew->next;
			tnode *new1=new tnode;
			new1=pnew->temp;
			delete pnew;
			return new1;
		}
	}
};

tnode *tree::exptree(char exp[20])
{
	int i=0;
	stack s;
	while(exp[i]!='\0')
	{
		tnode *p=new tnode;
		p->data=exp[i];
		
		if(isalpha(exp[i]))
		{
			s.push(p);
		}
		else
		{
			p->rc=s.pop();
			p->lc=s.pop();
			s.push(p);		
		}
		i++;
	}
	root=s.pop();
	return root;
}

void tree::nrec_inorder(tnode *n)
{
	stack s;
	tnode *temp;
	temp=n;
	while(temp!=NULL)
	{
		s.push(temp);
		temp=temp->lc;
	}
	while(!s.empty())
	{
		temp=s.pop();
		cout<<temp->data;
		temp=temp->rc;
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->lc;
		}
	}
	cout<<"\n";
}

void tree::nrec_preorder(tnode *n)
{
	tnode *temp;
	temp=n;
	stack s;
	s.push(temp);
	while(!s.empty())
	{
		temp=s.pop();
		cout<<temp->data;
		if(temp->rc!=NULL)
			s.push(temp->rc);
		if(temp->lc!=NULL)
			s.push(temp->lc);
	}
	cout<<"\n";	
}

void tree::nrec_postorder(tnode *n)
{
	tnode *temp;
	temp=n;
	stack s1,s2;
	s1.push(temp);
	while(!s1.empty())
	{
		temp=s1.pop();
		s2.push(temp);
		if(temp->lc!=NULL)
			s1.push(temp->lc);
		if(temp->rc!=NULL)
			s1.push(temp->rc);
	}
	while(!s2.empty())
	{
		temp=s2.pop();
		cout<<temp->data;
	}
	cout<<"\n";	
}

void tree::rec_inorder(tnode *n)
{
	tnode *temp;
	temp=n;
	if(temp!=NULL)
	{
		if(isalpha(temp->data))
			cout<<temp->data;
		else
		{
			cout<<'(';	
			rec_inorder(temp->lc);
			cout<<temp->data;
			rec_inorder(temp->rc);
			cout<<')';
		}
	}
}

void tree::rec_preorder(tnode *n)
{
	tnode *temp;
	temp=n;
	if(temp!=NULL)
	{
		cout<<temp->data;
		rec_preorder(temp->lc);
		rec_preorder(temp->rc);
	}
}

void tree::rec_postorder(tnode *n)
{
	tnode *temp;
	temp=n;
	if(temp!=NULL)
	{
		rec_postorder(temp->lc);
		rec_postorder(temp->rc);
		cout<<temp->data;
	}	
}
int main()
{
	int ch,ans;
	tree t;
	tnode *n;
	char exp[20];
	do
	{
		cout<<"\nEnter your choice"<<" ";
		cout<<"\n1-Expression tree\n2-Recursive inorder\n3-Recursive preoreder\n4-Recursive postorder";
		cout<<"\n5-Non-Recursive inorder\n6-Non-Recursive preoreder\n7-Non-Recursive postorder\n8-Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"Enter postfix expression\n";
				cin>>exp;
				n=t.exptree(exp);
				break;
			case 2: t.rec_inorder(n);
				break;
			case 3: t.rec_preorder(n);
				break;
			case 4: t.rec_postorder(n);
				break;
			case 5: t.nrec_inorder(n);
				break;
			case 6: t.nrec_preorder(n);
				break;
			case 7: t.nrec_postorder(n);
				break;
			case 8: return 1;
		}
	}while(ch>0&&ch<9);
}

/*
OUTPUT-
Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
1
Enter postfix expression
ab+c*

Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
2
((a+b)*c)
Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
3
*+abc
Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
4
ab+c*
Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
5
a+b*c

Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
6
*+abc

Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
7
ab+c*

Enter your choice 
1-Expression tree
2-Recursive inorder
3-Recursive preoreder
4-Recursive postorder
5-Non-Recursive inorder
6-Non-Recursive preoreder
7-Non-Recursive postorder
8-Exit
8
*/

