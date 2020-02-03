#include<iostream>
using namespace std;
#define infi 100000
#define row 20
#define col 20
class graph1
{
	int nodes,graph[row][col];
	public:
	graph1();
	void creategraph();
	void prims_algo();
};
graph1::graph1()
{
	int i,j;	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			graph[i][j]=0;
}
void graph1::creategraph()
{
	int i,j;
	cout<<"\nEnter total no. of nodes-";
	cin>>nodes;
	cout<<"\nEnter adjancy matrix-";
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			cout<<"\n";
			cout<<"graph["<<i<<"]["<<j<<"]=";
			cin>>graph[i][j];
		}
	}
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
			{
				if(graph[i][j]==0)
					graph[i][j]=infi;
			}
	}
}
void graph1::prims_algo()
{
	int selected[row],i,j,ne;
	int false1=0,true1=1,min,x,y,mincost=0;
	for(i=0;i<nodes;i++)
	{
		selected[i]=false1;
	}
	selected[0]=true1;
	ne=0;
	while(ne<nodes-1)
	{
		min=infi;
		for(i=0;i<nodes;i++)
		{
			if(selected[i]==true1)
			{
				for(j=0;j<nodes;j++)
				{
					if(selected[j]==false1)
					{
						if(min>graph[i][j])
						{
							min=graph[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		selected[y]=true1;
		mincost=mincost+graph[x][y];
		ne=ne+1;
	}
	cout<<"\nMincost="<<mincost;
}
int main()
{
	graph1 g;
	int ch;
	do
	{
	cout<<"\n1-Create graph\n2-Minimum spanning tree using Prim's algorithm\n3-Exit";
	cout<<"\nPrint your choice-";
	cin>>ch;
	switch(ch)
	{
		case 1:g.creategraph();
			break;
		case 2:g.prims_algo();
			break;
		case 3:return 1;	
	}
	}while(ch>0&&ch<4);
}

/*

OUTPUT-
1-Create graph
2-Minimum spanning tree using Prim's algorithm
3-Exit
Print your choice-1

Enter total no. of nodes-7

Enter adjancy matrix-
graph[0][0]=0

graph[0][1]=20

graph[0][2]=0

graph[0][3]=0

graph[0][4]=0

graph[0][5]=4

graph[0][6]=0

graph[1][0]=20

graph[1][1]=0

graph[1][2]=8

graph[1][3]=0

graph[1][4]=0

graph[1][5]=0

graph[1][6]=7

graph[2][0]=0

graph[2][1]=8

graph[2][2]=0

graph[2][3]=6

graph[2][4]=0

graph[2][5]=0

graph[2][6]=0

graph[3][0]=0

graph[3][1]=0

graph[3][2]=6

graph[3][3]=0

graph[3][4]=10

graph[3][5]=0

graph[3][6]=9

graph[4][0]=0

graph[4][1]=0

graph[4][2]=0

graph[4][3]=10

graph[4][4]=0

graph[4][5]=15

graph[4][6]=11

graph[5][0]=4

graph[5][1]=0

graph[5][2]=0

graph[5][3]=0

graph[5][4]=15

graph[5][5]=0

graph[5][6]=0

graph[6][0]=0

graph[6][1]=7

graph[6][2]=0

graph[6][3]=9

graph[6][4]=11

graph[6][5]=0

graph[6][6]=0

1-Create graph
2-Minimum spanning tree using Prim's algorithm
3-Exit
Print your choice-2

Mincost=50

1-Create graph
2-Minimum spanning tree using Prim's algorithm
3-Exit
Print your choice-3
*/

