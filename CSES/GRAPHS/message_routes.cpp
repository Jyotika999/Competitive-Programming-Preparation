
// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>graph[100005];

void solve()
{
	
	ll n, m;
	cin>>n>>m;
	ll parent[n+5];
	ll vis[n+5];
	

	memset(parent, 0, sizeof(parent));
	memset(vis, 0, sizeof(vis));
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	queue<ll>q;
	
	q.push(1);
	parent[1]=-1;
	
	while(!q.empty())
	{
		ll cur = q.front();
		vis[cur]=1;
		q.pop();
		
		for(auto child : graph[cur])
		{
			if(!vis[child])
			{
				q.push(child);
				vis[child]=1;
				parent[child]=cur;
			}
		}
	}
	
	if(vis[n]==1)
	{
		// print path
		// using parent backtracking
		ll i=n;
		vector<ll>path;
		while(parent[i]!=-1)
		{
			path.push_back(i);
			i=parent[i];
		}
		path.push_back(i);
		reverse(path.begin(), path.end());
		
		cout<<path.size()<<"\n";
		for(auto i : path)
		cout<<i<<" ";
	}
	else
	{
		cout<<"IMPOSSIBLE\n";
	}
	
	
	
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