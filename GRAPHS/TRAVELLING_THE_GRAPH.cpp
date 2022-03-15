// Problem: Invite Friends,  Get Premium For Free
// Contest: CodeChef - CodeChef Starters 28 Division 1 (Unrated)
// URL: https://www.codechef.com/START28A/problems/TRAVELLING
// Memory Limit: 256 MB
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
	
	// by observation from various test cases
	// it can be seen that only the edges of types i, i+1 
	// needs to be connected for making minimal cost 
	
	vector<ll>dis;
	dis.resize(n+1, INT_MAX);
	vector<pair<ll,ll>>graph[n+1];
	
	// the edges which are already connected
	// making their weight   =0
	while(m--)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back({v, 0});
		graph[v].push_back({u, 0});
		
	}
	
	// the edges of required type which are not connected 
	// connecting them with weight = 1
	for(ll i=2;i<=n;i++)
	{
		// if(find(graph[i].begin(), graph[i].end(), {i-1, 0})==graph[i].end())
		{
		graph[i].push_back({i-1, 1});
		graph[i-1].push_back({i, 1});
		}
	}
	
	// finding the shortest path from 1 to n
	// use of dijesktra  beacuse i created a weighted graph
	
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
	dis[1]=0;
	pq.push({0, 1}); // {node, distance}

	while(!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		
		for(auto c : graph[cur.second])
		{
			ll child = c.first;
			ll wt = c.second;
			if(dis[child] > dis[cur.second]+wt)
			{
				dis[child]= dis[cur.second]+wt;
				pq.push({dis[child], child});
			}
		}
	}
	cout<<dis[n]<<"\n";
	
	
	
}
int main()
{
	ll tc=1;
	cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}