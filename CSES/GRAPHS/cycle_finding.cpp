// Problem: Cycle Finding
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1197
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class edge{
	public:
	ll u;
	ll v;
	ll wt;
};

vector<pair<ll,ll>>graph[100005];
// ll vis[100005];
// ll flag=0;
// ll cursum=0;
// vector<ll>cycle;

void solve()
{
	ll n,m;
	cin>>n>>m;
	ll relaxant[n];
	ll distance[n];
	memset(distance, 0, sizeof(distance));
	memset(relaxant, -1, sizeof(relaxant));
	
	vector<edge>e;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		// directed edge
		edge temp;
		temp.u = u;
		temp.v = v;
		temp.wt = wt;
		e.push_back(temp);
		graph[u].push_back({v, wt});
	}
	
	// bellman ford algorithm
	
	for(int i=1;i<=n;i++)
	{
		relaxant[i]=-1;
		distance[i]=0;
	}
	
	
	ll x;
	for(ll i=1;i<=n;i++)
	{
		x = -1;
		
		for(auto it : e)
		{
			ll u = it.u;
			ll v = it.v;
			ll wt = it.wt;
			
			if(distance[u]+wt < distance[v])
			{
				distance[v] = distance[u] + wt;
				relaxant[v]=u;
				x = v;
			}
		}
	}
	
	if(x==-1)
	{
		// no negative cycle detected in the nth iteration
		cout<<"NO\n";
	}
	else
	{
		// negative cycle detected
		
		// make sure that x is a node that is guaranteed to be
		// part of the negative weight cycle 
		vector<ll>cycle;
		
		for(ll i=1;i<=n;i++)
		{
			x = relaxant[x];
		}
		
		for(ll i=x;;i=relaxant[i])
		{
			cycle.push_back(i);
			if(i==x and cycle.size()>1)
			break;
		}
		
		reverse(cycle.begin(), cycle.end());
		
		cout<<"YES\n";
		for(ll i=0;i<cycle.size();i++)
		{
			cout<<cycle[i]<<" ";
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