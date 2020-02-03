#include<iostream>
#define INFINITY 999
using namespace std;
 class Dijkstra
{
    	private:
        int a[15][15];
        int predecessor[15],distance[15];
        bool mark[15];
        int source;
        int t;
        int v;
    	public:
        void create();
	int visit();
	void calculateDistance();
 	void output();
        void printPath(int);
};


void Dijkstra::create()
{
    	cout<<"Enter the number of vertices of the graph(should be > 0)\n";
    	cin>>v;
    	cout<<"Enter the adjacency matrix for the graph\n";
        cout<<"To enter infinity enter "<<INFINITY<<endl;
    	for(int i=0;i<v;i++)
        {
        	cout<<"Enter the (+ve)weights for the row "<<i<<endl;
        	for(int j=0;j<v;j++)
            {
            		cin>>a[i][j];
        	}
    	}
        cout<<"\n Adjancy matrix is-\n";
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<a[i][j];
                cout<<"\t";
        	}
            cout<<"\n";
    	}
}

int Dijkstra::visit()
{
    	int minDistance = INFINITY;
    	int visited;
    	for(int i=0;i<v;i++)
        {
        	if((!mark[i]) && ( minDistance >= distance[i]))
            {
            		minDistance = distance[i];
            		visited = i;
        	}
    	}
    	return visited;
}

void Dijkstra::calculateDistance()
{
	cout<<"Enter the source vertex\n";
    cin>>source;
	cout<<"\nEnter destination node-";
	cin>>t;
    for(int i=0;i<v;i++)
   	{
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[source]= 0;
   	int minDistance = INFINITY;
    int current;
   	int count = 0;
    while(count < t)
	{
        current= visit();
		mark[current] = true;
        for(int i=0;i<v;i++)
		{
            if((!mark[i]) && (a[current][i]>0) )
			{
                if(distance[i] > distance[current]+a[current][i])
				{
                    distance[i] = distance[current]+a[current][i];
                    predecessor[i] = current;
                }
            }
        }
        count++;
    }
}

void Dijkstra::printPath(int node)
{
    	if(node == source)
        cout<<(char)(node + 97)<<"..";
    	else if(predecessor[node] == -1)
        cout<<"No path from “<<source<<”to "<<(char)(node + 97)<<endl;
    	else
        {
        	printPath(predecessor[node]);
        	cout<<(char) (node + 97)<<"..";
    	}
}

void Dijkstra::output()
{
    	printPath(t);
        cout<<"->"<<distance[t]<<endl;
}

int main()
{
	int ch;
	Dijkstra G;
	do
	{
		cout<<"\n1-create gaph\n2-Dijkstra's shortest path\nPrint your choice-";
		cin>>ch;
		switch(ch)
		{
			case 1:G.create();
				break;
			case 2:G.calculateDistance();
    				G.output();
				break;
			case 3:return 0;
		}
	}while(ch>0&&ch<4);
}

/*
OUTPUT-
1-create gaph
2-Dijkstra's shortest path
Print your choice-1
Enter the number of vertices of the graph(should be > 0)
7
Enter the adjacency matrix for the graph
To enter infinity enter 999
Enter the (+ve)weights for the row 0
0 22 16 8 999 999 999
Enter the (+ve)weights for the row 1
22 0 20 999 2 7 2
Enter the (+ve)weights for the row 2
16 20 0 10 4 3 10
Enter the (+ve)weights for the row 3
8 999 10 0 999 6 999
Enter the (+ve)weights for the row 4
999 2 4 999 0 999 4
Enter the (+ve)weights for the row 5
999 7 3 6 999 0 9
Enter the (+ve)weights for the row 6
999 2 10 999 4 9 0

 Adjancy matrix is-
0	22	16	8	999	999	999
22	0	20	999	2	7	2
16	20	0	10	4	3	10
8	999	10	0	999	6	999
999	2	4	999	0	999	4
999	7	3	6	999	0	9
999	2	10	999	4	9	0

1-create gaph
2-Dijkstra's shortest path
Print your choice-2
Enter the source vertex
0

Enter destination node-6
a..d..f..g..->23

1-create gaph
2-Dijkstra's shortest path
Print your choice-2
Enter the source vertex
0

Enter destination node-3
a..d..->8

1-create gaph
2-Dijkstra's shortest path
Print your choice-3
*/


