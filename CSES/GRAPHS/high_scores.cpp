
// Problem: High Score
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1673
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct node{
	
	ll u,v,wt;
	node(ll x, ll y, ll w)
	{
		u=x;
		v=y;
		wt=w;
	}
};

void solve()
{
	ll n,m;
	cin>>n>>m;
	vector<node>edge;
	vector<ll>dis(n+1, INT_MAX);
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		edge.push_back(node(u, v, wt));
	}
	
	for(ll i=1;i<=n;i++)
	dis[i]=INT_MAX;
	dis[1]=0;
	
	// Step 2: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for (ll i = 1; i <= n -1; i++) {
        for (ll j = 0; j < m; j++) {
            ll u = edge[j].u;
            ll v = edge[j].v;
            ll weight = edge[j].wt;
            if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
                dis[v] = dis[u] + weight;
        }
    }
 
	// Step 3: check for negative-weight cycles.  The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle.  If we get a shorter
    // path, then there is a cycle.
    for (ll i = 0; i < m; i++) {
        ll u = edge[i].u;
        ll v = edge[i].v;
        ll weight = edge[i].wt;
        if (dis[u] != INT_MAX && dis[u] + weight < dis[v]) {
            	cout<<"-1\n";
            // printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply
                    // return
        }
    }
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
    	
    	sum+=dis[i];
    	// cout<<dis[i]<<"\n";
    }
    // cout<<dis[n-1]<<"\n";
	cout<<sum<<"\n";
	
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
