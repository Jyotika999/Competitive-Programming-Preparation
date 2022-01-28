// Problem: Game Routes
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1681
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector<ll>graph[100005];

ll ways[1000005];
bool vis[1000005];
void dfs(ll node)
{
	vis[node]=1;
	
	for(auto child : graph[node])
	{
		if(!vis[child])
		{
			ways[child]= (ways[child] + ways[node])%mod;
			dfs(child);
		}
	}
}

void solve()
{
	ll n,m;
	cin>>n>>m;
	memset(vis, 0, sizeof(vis));
	memset(ways, 0, sizeof(ways));
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	ways[1]=1;
	dfs(1);
	cout<<ways[n]<<"\n";
	
	
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