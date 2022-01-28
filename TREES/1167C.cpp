// Problem: C. News Distribution
// Contest: Codeforces - Educational Codeforces Round 65 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1167/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll parent[5000005];
ll sz[5000005];
// ll r[5000005];
 
ll find_parent(ll i)
{
	if(i==parent[i])
	return i;
	
	return parent[i]=find_parent(parent[i]);
}
void unionn(ll a, ll b)
{
	a = find_parent(a);
	b = find_parent(b);
	
	if(a!=b)
	{
		if(sz[a]<sz[b])
		{
			parent[a]=b;
			sz[b]+=sz[a];
			sz[a]=0;
		}
		else 
		{
			parent[b]=a;
			sz[a]+=sz[b];
			sz[b]=0;
		}
		// else
		// {
			// r[b]++;
			// parent[a]=b;
			// sz[b]+=sz[a];
		// }
	}
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++)
	{
		parent[i]=i;
		sz[i]=1;
		// r[i]=0;
	}
	
	for(ll i=1;i<=m;i++)
	{
		ll k;
		cin>>k;
		ll ar[k+1];
		for(ll j=1;j<=k;j++)
		{
			cin>>ar[j];
			// cout<<ar[j]<<" ";
		}
		
		// cout<<"\n";
		for(ll j=2;j<=k;j++)
		{
			// if(find_parent(ar[j-1])!=find_parent(ar[j]))
			unionn(ar[1], ar[j]);
		}
	}
	
	
	for(ll i=1;i<=n;i++)
	{
		// cout<<i<<" "<<parent[i]<<" "<<sz[parent[i]]<<"\n";
		cout<<sz[find_parent(i)]<<" ";
	}
	cout<<"\n";
	
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