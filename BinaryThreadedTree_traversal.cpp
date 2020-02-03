#include<iostream>
using namespace std;
class tnode
{
	public:
	char data;
	tnode *lc;
	tnode *rc;
	int lt;
	int rt;
};
class tree
{
	public:
	tnode *root;
	tree()
	{
		root->lc=root->rc=root;
		root->lt=0;
		root->rt=1;
	}
	void create();
	void create1(tnode *q,int bit);
	tnode *in_succ(tnode *t);
	void inorder();
	tnode *pre_succ(tnode *t);
	void preorder();
};
void tree::create()
{
	create1(root,0);
}
void tree::create1(tnode *q,int bit)
{
	tnode *p;
	char x;
	int i;
	cout<<"\nEnter the data(#for no data)-";
	cin>>x;
	if(x=='#')
		return;
	p=new tnode;
	p->data=x;
	if(bit==0)
	{
		p->lt=q->lt;
		p->lc=q->lc;
		q->lc=p;
		q->lt=1;
		p->rt=0;
		p->rc=q;
	}
	else
	{
		p->rt=q->rt;
		p->rc=q->rc;
		q->rc=p;
		q->rt=1;
		p->lt=0;
		p->lc=q;	
	}
	cout<<"\nEnter left child of "<<x;
	create1(p,0);
	cout<<"\nEnter right child of "<<x;
	create1(p,1);
}
tnode *tree::in_succ(tnode *t)
{
	if(t->rt==1)
	{
		t=t->rc;
		while(t->lt==1)
			t=t->lc;
		return t;
	}
	else
		return(t->rc);
}
void tree::inorder()
{
	tnode *t;
	t=root->lc;
	while(t->lt==1)
		t=t->lc;
	while(t!=root)
	{
		cout<<t->data;
		t=in_succ(t);
	}
}
tnode *tree::pre_succ(tnode *t)
{
	if(t->lt==1)
		return(t->lc);
	if(t->rt==1)
		return(t->rc);
	while(t->rt==0)
		t=t->rc;
	return(t->rc);
}
void tree::preorder()
{
	tnode *t;
	t=root->lc;
	while(t!=root)
	{
		cout<<t->data;
		t=pre_succ(t);
	}
}
int main()
{
	int ch;
	tree t;
	do
	{
	cout<<"\n1-Create binary threaded tree\n2-Inorder Traversal\n3-Preorder Traversal\n4-Exit";
	cout<<"\nPrint your choice-";
	cin>>ch;
	switch(ch)
	{
		case 1:t.create();
			break;
		case 2:t.inorder();
			break;
		case 3:t.preorder();
			break;
		case 4:return 1;
	}
	}while(ch>0&&ch<5);
}

/*
OUTPUT-
1-Create binary threaded tree                                                                                                                                                                                 
2-Inorder Traversal                                                                                                                                                                                           
3-Preorder Traversal                                                                                                                                                                                          
4-Exit                                                                                                                                                                                                        
Print your choice-1                                                                                                                                                                                           
                                                                                                                                                                                                              
Enter the data(#for no data)-a                                                                                                                                                                                
                                                                                                                                                                                                              
Enter left child of a                                                                                                                                                                                         
Enter the data(#for no data)-b                                                                                                                                                                                
                                                                                                                                                                                                              
Enter left child of b                                                                                                                                                                                         
Enter the data(#for no data)-d 

Enter left child of d                                                                                                                                                                                         
Enter the data(#for no data)-h                                                                                                                                                                                
                                                                                                                                                                                                              
Enter left child of h                                                                                                                                                                                         
Enter the data(#for no data)-#                                                                                                                                                                                
                                                                                                                                                                                                              
Enter right child of h                                                                                                                                                                                        
Enter the data(#for no data)-#                                                                                                                                                                                
                                                                                                                                                                                                              
Enter right child of d                                                                                                                                                                                        
Enter the data(#for no data)-i                                                                                                                                                                                
                                                                                                                                                                                                              
Enter left child of i                                                                                                                                                                                         
Enter the data(#for no data)-# 

Enter right child of i                                                                                                                                                                                        
Enter the data(#for no data)-#          

Enter right child of b                                                                                                                                                                                        
Enter the data(#for no data)-e                                                                                                                                                                                
                                                                                                                                                                                                              
Enter left child of e                                                                                                                                                                                         
Enter the data(#for no data)-#                                                                                                                                                                                
                                                                                                                                                                                                              
Enter right child of e                                                                                                                                                                                        
Enter the data(#for no data)-#                                                                                                                                                                                
                                                                                                                                                                                                              
Enter right child of a                                                                                                                                                                                        
Enter the data(#for no data)-c                                                                                                                                                                                
                                                                                                                                                                                                              
Enter left child of c                                                                                                                                                                                         
Enter the data(#for no data)-f                                                                                                                                                                                
                
Enter left child of f                                                                                                                                                                                         
Enter the data(#for no data)-#                                                                                                                                                                                
                                                                                                                                                                                                              
Enter right child of f                                                                                                                                                                                        
Enter the data(#for no data)-#                                                                                                                                                                                
                                                                                                                                                                                                              
Enter right child of c                                                                                                                                                                                        
Enter the data(#for no data)-g                                                                                                                                                                                
                                                                                                                                                                                                              
Enter left child of g                                                                                                                                                                                         
Enter the data(#for no data)-#                                                                                                                                                                                
                                                                                                                                                                                                              
Enter right child of g                                                                                                                                                                                        
Enter the data(#for no data)-#   

1-Create binary threaded tree                                                                                                                                                                                 
2-Inorder Traversal                                                                                                                                                                                           
3-Preorder Traversal                                                                                                                                                                                          
4-Exit                                                                                                                                                                                                        
Print your choice-2                                                                                                                                                                                           
hdibeafcg                                                                                                                                                                                                     
1-Create binary threaded tree                                                                                                                                                                                 
2-Inorder Traversal                                                                                                                                                                                           
3-Preorder Traversal                                                                                                                                                                                          
4-Exit                                                                                                                                                                                                        
Print your choice-3                                                                                                                                                                                           
abdhiecfg                                                                                                                                                                                                     
1-Create binary threaded tree                                                                                                                                                                                 
2-Inorder Traversal                                                                                                                                                                                           
3-Preorder Traversal                                                                                                                                                                                          
4-Exit                       
Print your choice-4 
*/                     
