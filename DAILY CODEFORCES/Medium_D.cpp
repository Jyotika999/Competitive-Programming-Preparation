// Problem: D. Roads not only in Berland
// Contest: Codeforces - Codeforces Beta Round #25 (Div. 2 Only)
// URL: https://codeforces.com/contest/25/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>rankk;
vector<ll>parent;

ll find_parent(ll node)
{
	if(node==parent[node])
	return node;
	return parent[node]=find_parent(parent[node]);
}

void unionn(ll a, ll b)
{
	a = find_parent(a);
	b = find_parent(b);
	
	if(a!=b)
	{
		if(rankk[a]>rankk[b])
		{
			parent[b]=a;
		}
		else if(rankk[b]>rankk[a])
		{
			parent[a]=b;
		}
		else
		{
			parent[a]=b;
			rankk[b]++;
		}
	}
}
void solve()
{
	ll n;
	cin>>n;
	
	rankk.resize(n+1);
	parent.resize(n+1);
	
	for(ll i=1;i<=n;i++)
	{
		rankk[i]=1;
		parent[i]=i;
	}
	
	vector<pair<ll,ll>>redundant_edges;
	
	for(ll i=1;i<=n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		
		if(find_parent(u)!=find_parent(v))
		{
			unionn(u,v);
		}
		else
		{
			redundant_edges.push_back({u,v});
		}
	}
	
	vector<ll>component_parent;
	for(ll i=1;i<=n;i++)
	{
		if(parent[i]==i) // represents this is one component
		{
			component_parent.push_back(i);
		}
	}
	
	ll least_days = component_parent.size();
	
	cout<<least_days<<"\n";
	
	for(ll day=0;day<=least_days-1;day++)
	{
		cout<<redundant_edges[day].first<<" ";
		cout<<redundant_edges[day].second<<" ";
		cout<<component_parent[day]<<" ";
		cout<<component_parent[day+1];
		cout<<"\n";
	}
	
	
	
	
}
int main()
{
		solve();
	
}