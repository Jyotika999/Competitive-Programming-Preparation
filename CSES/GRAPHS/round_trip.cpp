
// Problem: Round Trip
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1669
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>graph[100005];
bool vis[100005];
ll parent[100005];
stack<ll>track;
vector<ll>temp;
vector<ll>res;

void dfs(ll node, ll p)
{
	vis[node]=1;
	parent[node]=p;
	track.push(node);
	
	for(auto child : graph[node])
	{
		if(vis[child]==0)
		{
			dfs(child, node);
		}
		else if(vis[child]==1 and child!=p)
		{
			// cout<<"cycle\n";
			// return;
			// cycle detected 
			// vector<ll>res;
			if(res.size()==0)
			{
			res.push_back(child);
			while(!track.empty() and (track.top()!=child))
			{
				res.push_back(track.top());
				track.pop();
			}
			res.push_back(child);
			// if(temp.size()<=3)
			// {
				// temp=res;
			// }
			}
			return;
// 			
		}
	}
	if(track.top()==node)
	track.pop();
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(ll i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i, -1);
		}
	}
	
	if(res.size())
	{
		cout<<res.size()<<"\n";
		for(ll i=0;i<res.size();i++)
		cout<<res[i]<<" ";
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