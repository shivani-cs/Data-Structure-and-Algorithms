#include<iostream>
using namespace std;
class tnode
{
	public:
	int data;
	tnode *lc;
	tnode *rc;
	tnode(int s)
	{
		data=s;
		lc=NULL;
		rc=NULL;
	}
};

class tree
{
	public:
	tnode *root;
	tree()
	{
		root=NULL;
	}
	void create();
	void insert(int n);
	void display(tnode *root);
	int rec_search(tnode *root,int key);
	int nrec_search(tnode *root,int key);
	tnode *mirror_bst(tnode *root);
	int rec_cntleaf(tnode *root);
	int rec_node(tnode *root);
	int rec_height(tnode *root);
	void delete1(tnode *root,int key);

};

void tree::create()
{
	int n,ch;
	do
	{
		cout<<"Enter number\t";
		cin>>n;
		insert(n);
		cout<<"Do you want to continue inserting\t";
		cin>>ch;
	}while(ch==1);
}

void tree::insert(int data)
{
	tnode *p=NULL;
	tnode *q;
	p=new tnode(data);
	if(root==NULL)
	{
		root=p;
		return;
	}
	q=root;
	while(q!=NULL)
	{
		if(p->data<q->data)
		{
			if(q->lc==NULL)
			{
				q->lc=p;
				break;
			}
			else
				q=q->lc;
		}
		else
		{
			if(q->rc==NULL)
			{
				q->rc=p;
				break;
			}
			else
				q=q->rc;
		}
	}

}

void tree::display(tnode *root)
{
	tnode *p;
	p=root;
	if(p!=NULL)
	{
		display(p->lc);
		cout<<p->data<<"\t";
		display(p->rc);
	}
}

int tree::rec_search(tnode *root,int key)
{
	tnode *temp=root;
	if(temp!=NULL)
	{
		if(temp->data==key)
			return 1;
		else if(key<temp->data)
			rec_search(temp->lc,key);
		else
			rec_search(temp->rc,key);
	}

}

int tree::nrec_search(tnode *root,int key)
{
	tnode *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==key)
			return 1;
		else if(key<temp->data)
			temp=temp->lc;
		else
			temp=temp->rc;
	}
}

tnode *tree::mirror_bst(tnode *root)
{
	tnode *t=root,*temp;
	if(t!=NULL)
	{
		temp=t->lc;
		t->lc=t->rc;
		t->rc=temp;
		mirror_bst(t->lc);
		mirror_bst(t->rc);
	}
	return root;
}

int tree::rec_cntleaf(tnode *root)
{
	int i=0;
	tnode *t=root;
	if(t!=NULL)
	{
		if(t->lc==NULL&&t->rc==NULL)
			i=1;
		else
			i=rec_cntleaf(t->lc)+rec_cntleaf(t->rc);
	}
	return i;
}

int tree::rec_node(tnode *root)
{
	int i=0;
	tnode *t=root;
	if(t!=NULL)
		i=1+rec_node(t->lc)+rec_node(t->rc);
	return i;
}

int tree::rec_height(tnode *root)
{
	tnode *t=root;
	int hl=1,hr=1,d=1;
	if(t!=NULL)
	{
		if(t->lc==NULL&&t->rc==NULL)
			d=1;
		else
		{
			hl=hl+rec_height(t->lc);
			hr=hr+rec_height(t->rc);
			if(hr>hl)
				d=hr;
			else
				d=hl;
		}
	}
		return d;
}
void tree::delete1(tnode *root,int dkey)
{
	tnode *temp,*dltptr;
	temp=root;
	int temp1;
	if(temp==NULL)
		return;
	if(dkey<temp->data)
		delete1(temp->lc,dkey);
	else if(dkey>temp->data)
		delete1(temp->rc,dkey);
	else
 	{
		if(temp->lc==NULL)
		{
			temp1=temp->data;
			temp->data=(temp->rc)->data;
			(temp->rc)->data=temp1;
			if(dkey==root->data)
			{
				root=temp;
			}
			delete1(temp,dkey);
		}
		else if(temp->rc==NULL)
		{
			temp1=temp->data;
			temp->data=(temp->lc)->data;
			(temp->lc)->data=temp1;
			if(dkey==root->data)
			{
				root=temp;
			}
			delete1(temp,dkey);
		}
		else if(temp->lc!=NULL && temp->rc!=NULL)
		{
			dltptr=temp->lc;
			while(dltptr->rc!=NULL)
			{
				dltptr=dltptr->rc;
			}
			temp1=temp->data;
			temp->data=dltptr->data;
			dltptr->data=temp1;
			delete1(temp->lc,dkey);
		}
		else if(temp->lc==NULL && temp->rc==NULL)
		{
			delete temp;
		}
	}
}
int main()
{
	tree t;
	int ch,ans,i,key;
	tnode *n;

	do
	{
		cout<<"Enter\n1-Create bst\n2-Display\n3-Recursive search\n4-Non recursive search\n5-Mirror of bst\n6-Recursive counting leaf nodes\n7-Recursive counting nodes\n8-Recursive height\n";
		cout<<"Enter your choice\t";
		cin>>ch;
		switch(ch)
		{
		case 1: t.create();
				break;

		case 2: t.display(t.root);
				break;

		case 3: cout<<"\nEnter the key to be searched\t";
				cin>>key;
				i=t.rec_search(t.root,key);
				if(i==1)
					cout<<"Key is found\n";
				else
					cout<<"key is not found\n";
				break;

		case 4: cout<<"Enter the key to be searched\t";
				cin>>key;
				i=t.nrec_search(t.root,key);
				if(i==1)
					cout<<"Key is found\n";
				else
					cout<<"key is not found\n";
				break;

		case 5: n=t.mirror_bst(t.root);
				t.display(n);
				cout<<"\nTo obtain original BST\n";
				n=t.mirror_bst(t.root);
				t.display(n);
				break;

		case 6: i=t.rec_cntleaf(t.root);
				cout<<"\nNo of leaf nodes are\t"<<i;
				break;

		case 7: i=t.rec_node(t.root);
				cout<<"\nNo of nodes are\t"<<i;
				break;

		case 8: i=t.rec_height(t.root);
				cout<<"\nHeight of tree is\t"<<i;
				break;
		case 9: cout<<"\nEnter the key you want to delete-";
				cin>>key;
				t.delete1(t.root,key);
				break;
		case 10:return 0;

		}
		cout<<"\nEnter 1 to continue\t";
		cin>>ans;
	}while(ans==1);
	return 0;
}




/*
OUTPUT-

Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       1
Enter number    7
Do you want to continue inserting       1
Enter number    2
Do you want to continue inserting       1
Enter number    9
Do you want to continue inserting       1
Enter number    0
Do you want to continue inserting       1
Enter number    5
Do you want to continue inserting       1
Enter number    8
Do you want to continue inserting       1
Enter number    6
Do you want to continue inserting       1
Enter number    1
Do you want to continue inserting       0

Enter 1 to continue     1
Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       2
0 1 2 5 6 7 8 9
Enter 1 to continue     1
Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       3
Enter the key to be searched    5
Key is found

Enter 1 to continue     1
Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       4
Enter the key to be searched    10
key is not found

Enter 1 to continue     1
Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       5
9 8 7 6 5 2 1 0
To obtain original BST
0 1 2 5 6 7 8 9
Enter 1 to continue     1
Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       6
No of leaf nodes are    3
Enter 1 to continue     1
Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       7
No of nodes are 8
Enter 1 to continue     1
Enter
1-Create bst
2-Display
3-Recursive search
4-Non recursive search
5-Mirror of bst
6-Recursive counting leaf nodes
7-Recursive counting nodes
8-Recursive height
Enter your choice       8
Height of tree is       4
Enter 1 to continue     5
*/
