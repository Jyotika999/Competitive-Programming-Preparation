
// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>graph[100005];
ll flag=1;
bool vis[100005];
ll color[100005];

void dfs(ll node, ll c)
{
	vis[node]=1;
	color[node]=c;
	
	for(auto child : graph[node])
	{
		if(!vis[child])
		{
			vis[child]=1;
			// color[]
			dfs(child, c^1);
		}
		else
		{
			if(color[child]==c)
			{
				flag=0;
				return;
			}
		}
	}
}

void solve()
{
	ll n,m;
	cin>>n>>m;
	flag=1;
	memset(vis, 0, sizeof(vis));
	memset(color, 0, sizeof(color));
	
	for(ll i=1;i<=m;i++)
	{
		ll u, v;
		cin>>u>>v;
		// cout<<u<<" "<<v<<"\n";
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			// cout<<i<<" \n";
			dfs(i, 0);
		}
	}
// 	
	if(flag==0)
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			cout<<color[i]+1<<" ";
		}
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