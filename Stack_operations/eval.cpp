#include<iostream>
#include"stack.cpp"
#include<string.h>
int calc(int a,int b,char oper)
{
 	int result;
 	if(oper=='+')
	{
 		result=a+b;
  		return result;
	}
	else if(oper=='-')
	{
 		result=a-b;
 		return result;
	}
	else if(oper=='*')
	{
 		return(a*b);
	}
	else if(oper=='/')
	{
  		return(a/b);
	}
	else
	{
  		return(0);
	}
}
void eval()
{
   	char val1;
  	stack <char> st,s;
   	char ans[20];
    char ans1[20];
	int index=0;
	int i=0,value,k,j=0,m=0;
	int ch;
	cout<<"postfix press 1"<<endl<<"prefix press 2";
	cin>>ch;
  	cout<<"Enter expression";
  	cin>>ans;
   	int exp=strlen(ans);
    	//cout<<exp;
  	if(ch==2)
  	{
 		while(i<exp)
		{
 			s.push(ans[i]);
 			i++;
 		}
 		char val;
 		char prefix1[20]="";
		while(j<exp)
		{
 			val1=s.pop();
 			ans[j]=val1;
			j++;
		}
  	}
	i=0;
	while(i<exp)
	{
 		if(isalpha(ans[i]))
 		{
   			cout<<"Enter value";
   			int val;
   			cin>>val;
   			st.push(val);
 		}
		else
		{
  			int op1=st.pop();
  			int op2=st.pop();
  			char oper=ans[i];
  			if(ch==1)
  				value=calc(op2,op1,oper);
			else
  			{
    			value=calc(op1,op2,oper);
  			}
   			st.push(value);
		}
		i=i+1;
	}
	int result=st.pop();
	cout<<result;
}

int main()
{
 eval();
}

/*
OUTPUT-
postfix press 1
prefix press 2
1
Enter expression ab+c*
Enter value 1
Enter value 2
Enter value 3
9

postfix press 1
prefix press 2
2
Enter expression *a+bc
Enter value 1
Enter value 2
Enter value 3
9

*/
