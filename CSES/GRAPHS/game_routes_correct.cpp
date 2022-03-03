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

unordered_map<ll,ll>dp;
vector<ll>graph[100005];

ll dfs(ll src, ll dst)
{
	if(src == dst)
	return 1;
	
	if(dp.find(src)!=dp.end())
	return dp[src];
	
	ll res = 0;
	
	for(auto child : graph[src])
	{
		res = (res + dfs(child, dst))%mod;
	}
	
	return dp[src] = res;
	
}	
	
void solve()
{
	ll n,m;
	cin>>n>>m;
	
	// for(ll i=1;i<=n;i++)
	// {
		// dis[i]=-1;
		// parent[i]=-1;
	// }
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	
	cout<<dfs(1, n)<<"\n";
	
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