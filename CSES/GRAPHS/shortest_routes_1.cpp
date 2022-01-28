// Problem: Shortest Routes I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1671
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll>>graph[100005];
ll dis[100005];
ll vis[100005];

void solve()
{
	ll n,m;
	cin>>n>>m;
	// memset(dis, IN, sizeof(dis));
	for(ll i=1;i<=n;i++)
	{
		dis[i]= 1e18;
		vis[i]=0;
	}
	for(ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		graph[u].push_back({v,wt});
		// graph[v].push_back({u, wt});
	}
	
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
	
	pq.push({0, 1});
	dis[1]=0;
	
	while(!pq.empty())
	{
		auto cur = pq.top();
		ll curdis = cur.first;
		ll curnode = cur.second;
		pq.pop();
		
		if(vis[curnode])
		continue;
		
		vis[curnode]++;
		
		for(auto c : graph[curnode])
		{
			ll curchild = c.first;
			ll curwt = c.second;
			
			if(dis[curnode] + curwt < dis[curchild])
			{
				dis[curchild] = dis[curnode] + curwt;
				pq.push({dis[curchild], curchild});
			}
		}
		
		
	}
	for(ll i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	
	
	
}
int main()
{
	ll tc=1;
	// cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}