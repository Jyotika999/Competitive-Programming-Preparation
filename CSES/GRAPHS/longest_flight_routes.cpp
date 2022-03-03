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
#define mod 1000000007

vector<ll>graph[100005];
ll dp[100005];
ll vis[100005];

ll dfs(ll src, ll dst)
{
	if(src == dst)
	return dp[src]=1;
	
	if(dp[src]!=-1)
	return dp[src];
	
	vis[src]=1;
	
	ll res=0;
	for(auto child : graph[src])
	{
		if(!vis[child])
		{			
			res = max(res, dfs(child, dst));	
		}
		else
		{
			res = max(res, dp[child]);
		}
	}
	
	if(res==0)
	{
		return dp[src] = INT_MIN;
	}	
	else
	{
		return dp[src] = res+1;
	}
	
	
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	
	ll ans = dfs(1, n);
	
	if(dp[n]==-1)
	{
		cout<<"IMPOSSIBLE\n";
		return;
	}
	else
	{
		cout<<ans<<"\n";
	}
	ll node = 1;
	while(node!=n)
	{
		cout<<node<<" ";
		ll res = 0;
		for(auto child : graph[node])
		{
			if(dp[child]>dp[res])
			{
				res = child;
			}
		}
		node = res;
	}
	
	cout<<node<<"\n";
	// cout<<dp[n]<<"\n";
	
	
	
	
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