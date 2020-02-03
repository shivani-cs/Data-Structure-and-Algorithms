#include<iostream>
#include"stack.cpp"
#include<string.h>
using namespace std;
void postfix(char formul[20]);
void postfix1(char formul[20]);
int priority(char x);
void prefix(char formula1[20]);
int main()
{
 	char formula[20];
	int ch;
	do
	{
	cout<<"\nEnter your choice-"<<"\n1-infix to postfix"<<"\n2-infix to prefix\n";
	cin>>ch;
	cout<<"Enter expression:";
	cin>>formula;
	switch(ch)
	{
		case 1: postfix(formula);
			break;
		case 2: prefix(formula);
			break;
		  
		default: cout<<"wrong choice.";
			 break;
	}
	}while(ch>0&&ch<3);
	return 0;
}
void postfix(char formul[20])
{
	int x;
	char tokenout,toptoken;
	char token;

	char post[20];
	stack <char> st;

	int looper=0,j=0;
	while(looper<strlen(formul))
	{
		token=formul[looper];
		if(token=='(')
		{
			st.push(token);
		}
		else if(token==')')
		{
			token=st.pop();
			while(token!='(')
			{
				post[j]=token;
				j++;
				token=st.pop();
			}
		}
		else if((token=='%')||(token=='*')||(token=='+')||(token=='-')||(token=='/')||(token=='$'))
		{
			toptoken=st.stacktop();
			while((!st.stackempty())&&(priority(token)<=priority(toptoken)))
			{
				tokenout=st.pop();
				post[j]=tokenout;
				j++;
				toptoken=st.stacktop();
			}
			st.push(token);
		}
		else
		{
			post[j]=token;
			j++;
		}
		looper=looper+1;
	}
	while(!st.stackempty())
	{
		token=st.pop();
		post[j]=token;
		j++;
	}
	post[j]='\0';
	cout<<post;
}
void postfix1(char formul[20])
{
	int x;
	char tokenout,toptoken;
	char token;
	char post[20];
	stack <char> st;

	int looper=0,j=0;
	while(looper<strlen(formul))
	{
	token=formul[looper];
	if(token=='(')
	{
		st.push(token);
	}
	else if(token==')')
	{
		token=st.pop();
		while(token!='(')
		{
			post[j]=token;
			j++;
			token=st.pop();
		}
	}
	else if((token=='%')||(token=='*')||(token=='+')||(token=='-')||(token=='/')||(token=='$'))
	{
		toptoken=st.stacktop();
		while((!st.stackempty())&&(priority(token)<=priority(toptoken)))
		{
			tokenout=st.pop();
			post[j]=tokenout;
			j++;
			toptoken=st.stacktop();
		}
		st.push(token);
	}
	else
	{
		post[j]=token;
		j++;
	}
	looper=looper+1;
	}
	while(!st.stackempty())
	{
		token=st.pop();
		post[j]=token;
		j++;
	}
	post[j]='\0';
	int k=0,lent;
	lent=strlen(post);
	while(k<lent)
	{
  		st.push(post[k]);
  		k++;
	}
	int l=0;
 	char val;
 	char prefix1[20]="";
	while(l<lent)
	{
 		val=st.pop();
 		prefix1[l]=val;
		l++;
	}
	cout<<prefix1;
}
int priority(char token)
{
	if(token=='^'|| token=='$')
		return 3;
	if((token=='*') || (token=='/'))
		return 2;
	if((token=='+') || (token=='-'))
		return 1;
	else
		return 0;
}
void prefix(char formula1[20])
{
 	stack<char> s;
 	int expsize;
 	expsize=strlen(formula1);
 	int i=0,j=0;
 	while(i<expsize)
	{
 		s.push(formula1[i]);
 		i++;
 	}
 	char val;
 	char prefix1[20]="";
	while(j<expsize)
	{
		 val=s.pop();
 		if(val=='(')
 		{
 			val=')';
 		}
 		else if(val==')')
		{
			val='(';
		}
 		prefix1[j]=val;
		j++;
	}
	postfix1(prefix1);
}

/*
OUTPUT-
Enter your choice-
1-infix to postfix
2-infix to prefix
1
Enter expression:a*b-((c+d)+e)+f
ab*cd+e+-f+
Enter your choice-
1-infix to postfix
2-infix to prefix
2
Enter expression:a*b((c+d)+e)+f
+*ab++cdef
*/

