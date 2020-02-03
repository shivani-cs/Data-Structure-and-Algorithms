#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 10
	int n,cnt=0,cnt1=0;
	
	typedef struct _treenode treenode;
	struct _treenode
	{
		int freq;
		char ch;
	
		treenode *left, *right;
	};
	typedef struct _pq
	{
		int heap_size;
		treenode *A[max];
	}PQ;
	
	struct BinaryCodes
	{
		char ch;
		char word[10];
	}codes[max];
	
	void create_pq (PQ *p)
	{
		p->heap_size = 0;
	}
	
	
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return i*2+1;
	}
	int right(int i)
	{
		return i*2+2;
	}


void main()
{
	int choice,i;
	char ch[max];
	int w[max];
	treenode *root;
	char word[max];
	char msg[max];
	treenode *build_huffman (char cha[max],int freqs[max],int num);

	void insert_pq(PQ *p,treenode *r);
	treenode *extract_min_pq (PQ *p);
	void preorder(treenode *p,int i,char word[]);
	void encode(char msg[]);
	void decode(treenode *r,char msg[]);

	do
	{
	printf("\n\n\t1.create huffman tree");
	printf("\n\t2.encode a message");
	printf("\n\t3.decode a message");
	printf("\n\t4.display");
	printf("\n\t5.exit");
        printf("\n\tselect choice::\t");
           scanf("%d",&choice);

           switch(choice)
           {
                      case 1:
                      		printf("\nenter no. of characters:");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
				                 printf("\nenter no.of frequencies::");
				                 scanf(" %c%d",&ch[i],&w[i]);
				}
				      root= build_huffman (ch,w,n);
				      preorder(root,0,word);
				      break;
                      case 2:
		      		printf("\nenter message:");
		              	scanf("%s",msg);
		              	encode(msg);
		             	break;
                      case 3:
                      		printf("\nenter encoded message:");
                      		scanf("%s",msg);
                      		decode(root,msg);
                      		break;
                      case 4:
                      		printf("\nprefix codes");
                      		for(i=0;i<n;i++)
                      		printf("\n\t %c : %s",codes[i].ch,codes[i].word);
                      		break;
                      case 5:
                      		exit(0);
                      		break;
                      
				default:printf("\ninvalid choice...");
                      }
           }
           while(choice!=5);
}

void heapify(PQ *p, int i)
{           
           int l,r,smallest;
           treenode *t;                   
   		cnt1++;
            l = left(i);
            r = right(i);

            if(l < p->heap_size && p->A[l]->freq < p->A[i]->freq) 
            smallest = l;
            else
            smallest = i;
            
	    if(r < p->heap_size && p->A[r]->freq < p->A[smallest]->freq)
            smallest = r;
            
	    if(smallest !=i)
            {
                t = p->A[i];
                p->A[i] = p->A[smallest];
                p->A[smallest] = t;
                heapify(p,smallest);
                
                
            }
            printf("\nlog(n)%d",cnt1);
            cnt1=0;
           
         
            
}
void insert_pq (PQ *p,treenode *r)
{
	    int i;
	    p->heap_size++;
	    i = p->heap_size-1;
	    while((i>0)&& (p->A[parent(i)]->freq > r->freq))
	    {
			p->A[i] = p->A[parent(i)];
			i = parent(i);
	    }
		p->A[i] = r;
}

treenode *extract_min_pq(PQ *p)
{
    		treenode *r;
    		if(p->heap_size == 0)
    		{
       			 printf("heap underflow!!!!!\n");
        		 exit(1);
    		}
        r = p->A[0];
        p->A[0] = p->A[p->heap_size-1];
        p->heap_size--;
        
        heapify(p,0);
        printf("\nn-log(n)%d",cnt++);
        return r;
}

treenode *build_huffman(char cha[max],int freqs[max],int num)
{
	    int i,n;
	    treenode *x,*y,*z;
	    PQ p;
	    create_pq(&p);
	    for(i=0;i<num;i++)
    		{
			x= malloc (sizeof (treenode));
			x->left = NULL;
			x->right = NULL;
			x->freq = freqs[i];
			x->ch = cha[i];
			insert_pq(&p,x);
    		}
    n = p.heap_size-1;
    	  for(i=0;i<n;i++)
    		{
			z = malloc (sizeof (treenode));
			x = extract_min_pq (&p);
			y = extract_min_pq (&p);
			z->left = x;
			z->right = y;

			z->freq = x->freq + y->freq;
			insert_pq(&p,z);
    }
    return extract_min_pq(&p);
}

void preorder(treenode *p,int i,char word[])
{
    	int j;
    	if(p!=NULL)
    	{
        	if(p->left==NULL && p->right==NULL)
        	{
			    word[i] = 0;
			    printf("\n%c --- %s",p->ch,word);
			    j = n++;
			    codes[j].ch = p->ch;
			    strcpy(codes[j].word,word);
        	}
        word[i] = '0';
        preorder(p->left,i+1,word);
        word[i] = '1';
        preorder(p->right,i+1,word);
    }
}
void encode(char msg[])
{
	int i,j;
	for(i=0;msg[i]!= '\0';i++)
	{
		for(j=0;j<n;j++)
		{
			if(msg[i]==codes[j].ch)
			{
				printf("%s",codes[j].word);
				break;
			}
		}
	}
}
void decode(treenode *r,char msg[])
{
	int i=0;
	treenode *t=r;
	while(msg[i]!='\0')
	{
			if(msg[i]=='0')
			t=t->left;
			else
			t=t->right;
			if(t->left==NULL && t->right==NULL)
			{
				printf("%c",t->ch);
				t=r;
			}
	i++;
	}
} 
     
/*OUTPUT
info-16@info16-OptiPlex-3020:~/Desktop$ gcc huff.c
info-16@info16-OptiPlex-3020:~/Desktop$ ./a.out


	1.create huffman tree
	2.encode a message
	3.decode a message
	4.display
	5.exit
	select choice::	1       

enter no. of characters:5

enter no.of frequenciesa  2

enter no.of frequenciesb 1

enter no.of frequenciesc 1

enter no.of frequenciesd 3

enter no.of frequenciese 6

e --- 0
d --- 10
a --- 110
b --- 1110
c --- 1111

	1.create huffman tree
	2.encode a message
	3.decode a message
	4.display
	5.exit
	select choice::	2

enter messageaeeebcd
1100001110111110

	1.create huffman tree
	2.encode a message
	3.decode a message
	4.display
	5.exit
	select choice::	3

enter encoded massage1101110111011111000
abbcdee

	1.create huffman tree
	2.encode a message
	3.decode a message
	4.display
	5.exit
	select choice::	4

prefix codes
	  : 
	  : 
	  : 
	  : 
	  : 
	 e : 0
	 d : 10
	 a : 110
	 b : 1110
	 c : 1111

	1.create huffman tree
	2.encode a message
	3.decode a message
	4.display
	5.exit
	select choice::	5

info-16@info16-OptiPlex-3020:~/Desktop$--*/

           




