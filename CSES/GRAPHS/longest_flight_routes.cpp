// Problem: Longest Flight Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1680
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,m;
	cin>>n>>m;
	ll dis[n+1];
	ll parent[n+1];
	vector<ll>graph[n+1];
	
	for(ll i=1;i<=n;i++)
	{
		dis[i]=-1;
		parent[i]=-1;
	}
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	
	priority_queue<pair<ll,ll>>pq;
	pq.push({0, 1});
	dis[1]=0;
	parent[1]=-1;
	
	while(!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		ll curdis = cur.first;
		ll curnode = cur.second;
		
		if(dis[curnode] > curdis)
		continue;
		
		for(auto child : graph[curnode])
		{
			if(dis[child] < curdis +1)
			{
				dis[child]=curdis+1;
				// cout<<child<<" "<<dis[child]<<"\n";
				parent[child]=curnode;
				pq.push({dis[child], child});
			}
		}
	}
	
	
	if(dis[n]==-1)
	{
		cout<<"IMPOSSIBLE\n";
		return;
	}
	// for(ll i=1;i<=n;i++)
	// {
		// cout<<parent[i]<<" "<<dis[i]<<"\n";
	// }
	// cout<<dis[n]<<"\n";
	
	vector<ll>path;
	ll i=n;
	while(parent[i]!=-1)
	{
		// cout<<i<<" ";
		path.push_back(i);
		i=parent[i];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	
	cout<<path.size()<<"\n";
	for(ll i=0;i<path.size();i++)
	{
		cout<<path[i]<<" ";
	}
	
	
	
	
	
	
	
}
int main()
{
	ll tc=1;
	// cin>>tc;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}