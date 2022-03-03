// GRAPH IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

class Graph{
	public:
	int v;
	list<int>*l ;
	Graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}
	void addedge(int u, int v)
	{
		// u->v
		l[u].push_back(v);
		// v->u 
		l[v].push_back(u);
	}
	void print_graph()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<" : ";
			for(int child : l[i])
			{
				cout<<child<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}	
}; 

int main()
{
	Graph g(4);
	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(1, 2);
	g.addedge(2, 3);
	g.print_graph();
}



