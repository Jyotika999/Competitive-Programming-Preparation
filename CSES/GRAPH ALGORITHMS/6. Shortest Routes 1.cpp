// shortest routes
// finding the length of the shortest route from origin/source to other vertices

// use of dijekstra algorithm in finding the shortest path of the weighted graph


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<ll,ll>>g[1000001];
bool vis[1000001];
ll dis[1000001];
ll n;
ll mindistance(ll dis[], bool vis[])
{
	ll mini = INT_MAX;
	ll min_index ;
	
	for(ll i=0;i<n;i++)
	{
		if(vis[i]==false && dis[i]<=mini)
		{
			mini = dis[i];
			min_index = i;
		}
	}
	return min_index;
}


void dijekstra(ll src)
{
	for(ll i=1;i<=n;i++)
	{
		vis[i]=false;
		dis[i]= INT_MAX;
	}
	
	dis[src]=0;
	for(ll i=1;i<=n;i++)
	{
		ll u = mindistance(dis,vis);
		vis[u]=true;
		
		for(ll v=1;v<=n;v++)
		{
			if(vis[v]==false  && (dis[u]!=INT_MAX) && (dis[u]+g[u][v]<dis[v]))
				dis[v] = dis[u] + g[u][v];
		
		
		}
	}
	
	for(ll i=1;i<=n;i++)
	{
		cout<<dis[i]<<"\n";
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll m;
	cin>>n>>m;
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		
		g[u].push_back({v,wt});
		g[v].push_back({u,wt});
	}
	
	dijekstra(1);
}
