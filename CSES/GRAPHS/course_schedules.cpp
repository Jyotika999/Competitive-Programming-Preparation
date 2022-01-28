// Problem: Course Schedule
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1679
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>graph[100005];
ll indegree[100005];

void solve()
{
	ll n,m;
	cin>>n>>m;
	memset(indegree, 0, sizeof(indegree));	
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		// directed graph
		// you need to complete u , before completing v
		indegree[v]++;
	}
	
	queue<ll>q;
	for(ll i=1;i<=n;i++)
		if(indegree[i]==0)
			q.push(i);
	
	if(q.empty())
	{
		cout<<"IMPOSSIBLE\n";
		return;
	}
	vector<ll>path;
	
	while(!q.empty())
	{
		ll cur = q.front();
		q.pop();
		// cout<<cur<<" ";
		path.push_back(cur);
		for(auto c:graph[cur])
		{
			indegree[c]--;
			
			if(indegree[c]==0)
			q.push(c);
		}
	}
	
	if(path.size()!=n)
	{
		cout<<"IMPOSSIBLE\n";
		return;
	}
	
	for(ll i=0;i<n;i++)
	cout<<path[i]<<" ";
	cout<<"\n";
	
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