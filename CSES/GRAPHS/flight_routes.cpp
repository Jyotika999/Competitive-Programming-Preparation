// Problem: Flight Routes
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1196
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INT_MAX 1e18
vector<pair<ll,ll>>graph[100005];
priority_queue<ll, vector<ll>, greater<ll>>pq;

void solve()
{
	ll n,m,k;
	cin>>n>>m>>k;
	// also , see k is very small
	// try to look into the constraints of the question
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		graph[u].push_back({v, wt});
	}
	
	vector<ll>dis[n+1];
	for(ll i=1;i<=n;i++)
	{
		dis[i].resize(k);
		for(ll j=0;j<k;j++)
		dis[i][j]=INT_MAX;
	}
	
	// pair<ll,ll> // distance, node
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
	
	pq.push({0, 1});
	
	while(!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		ll curnode = cur.second;
		ll curdis = cur.first;
		
		if(curdis > dis[curnode][k-1])
		continue;
		// cout<<curnode<<" "<<curdis<<"\n";
		for(auto c : graph[curnode])
		{
			ll curchild = c.first;
			ll curwt = c.second;
			
			if(dis[curchild][k-1] > curwt + curdis)
			{
				dis[curchild][k-1]= curwt + curdis;
				pq.push({dis[curchild][k-1], curchild});
				sort(dis[curchild].begin(), dis[curchild].end());
			}
		}
		
		
		
	}
	
	for(ll i=0;i<k;i++)
	cout<<dis[n][i]<<" ";
	
	
	
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