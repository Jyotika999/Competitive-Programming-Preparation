// Problem: Flight Discount
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1195
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct edge{
	ll u,v, wt;
	edge(ll u1, ll v1,ll w)
	{
		this->u = u1;
		this->v = v1;
		this->wt = w;
	}
};

void dijekstra(ll node, vector<ll>&dis, vector<pair<ll,ll>>graph[], vector<bool>&vis)
{
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
	
	dis[node]=0;
	pq.push({0, node});
	
	while(!pq.empty())
	{
		auto cur = pq.top();
		ll curnode = cur.second;
		ll curdis = cur.first;
		pq.pop();
		
		if(vis[curnode])
		continue;
		
		vis[curnode]=1;
		
		for(auto c : graph[curnode])
		{
			ll child = c.first;
			ll wt = c.second;
			
			if(wt + curdis < dis[child])
			{
				dis[child]= wt+curdis;
				pq.push({dis[child], child});
			}
		}
		
	}
	
	
	
	
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	
	vector<pair<ll,ll>>graph1[n+5];
	vector<pair<ll,ll>>graph2[n+5];
	// ll dis1[n+5];
	// ll dis2[n+5];
	vector<ll>dis1(n+5);
	vector<ll>dis2(n+5);
	vector<bool>vis1(n+5,0);
	vector<bool>vis2(n+5,0);
	
	for(ll i=0;i<=n;i++)
	{
		dis1[i]=1e18;
		dis2[i]=1e18;
	}
	vector<edge*>e;
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		graph1[u].push_back({v,wt}); // direct edge
		graph2[v].push_back({u, wt}); // reversed edge
		// directed graph
		e.push_back(new edge(u,v, wt));
	}
	
	dijekstra(1, dis1, graph1, vis1);
	dijekstra(n, dis2, graph2, vis2);
	
	ll mindis=1e18;
	
	for(auto it: e)
	{
		ll u = it->u;
		ll v = it->v;
		ll w = it->wt;
		ll temp = dis1[u]+ (w)/2 + dis2[v]; 
		// cout<<dis1[u]<<" "<<dis2[v]<<"\n";
		// cout<<u<<" "<<v<<" "<<w<<" "<<temp<<"\n";
		mindis = min(mindis, temp);
		
	}
	cout<<mindis<<"\n";
	
	
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