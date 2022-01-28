
// Problem: C. Not Assigning
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>graph[100005];
bool vis[100005];
map<pair<ll,ll>, ll>wt;
void dfs(ll node, ll c)
{
	vis[node]=1;
	
	for(auto child : graph[node])
	{
		if(!vis[child])
		{
			if(c==2)
			{
				wt[{node, child}]=5;
				wt[{child, node}]=5;
				dfs(child, 5);
			}
			else
			{
				wt[{node, child}]=2;
				wt[{child, node}]=2;
				dfs(child, 2);
			}
		}
	}
}
void solve()
{
	ll n;
	cin>>n;
	map<ll, pair<ll,ll>>edges;
	
	for(ll i=1;i<=n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		if(u>v)
		swap(u,v);
		edges[i]={u,v};
	}
	
	ll leaf=0;
	for(ll i=1;i<=n;i++)
	{
		if(graph[i].size()>=3)
		{
			cout<<"-1\n";
			return;
		}
		if(graph[i].size()==1)
		{
			leaf=i;
		}
		
	}
	
	dfs(leaf, 2);
	
	for(auto it : edges)
	{
		cout<<wt[it.second]<<" ";
	}
	cout<<"\n";
	
}
int main()
{
	ll tc=1;
	cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		for(int i=1;i<=100005;i++)
		{
			graph[i].clear();
			vis[i]=0;
		}
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}