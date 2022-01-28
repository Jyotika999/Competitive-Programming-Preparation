
// Problem: Building Roads
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1666
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll parent[100005];
ll sz[100005];

ll find_parent(ll num)
{
	if(num == parent[num])
	return num;
	
	else
	return parent[num]=find_parent(parent[num]);
}
void unionn(ll a, ll b)
{
	a = find_parent(a);
	b = find_parent(b);
	
	if(a<b)
	{
		parent[a]=b;
		sz[b]+=a;
	}
	else if(a>b)
	{
		parent[b]=a;
		sz[a]+=b;
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
	}
	
	for(ll i=1;i<=m;i++)
	{
		ll u, v;
		cin>>u>>v;
		unionn(u, v);
	}
	
	vector<ll>ans;
	
	for(ll i=1;i<=n;i++)
	{
		if(i==parent[i])
		{
			ans.push_back(i);
		}
	}
	
	cout<<ans.size()-1<<"\n";
	for(ll i=1;i<ans.size();i++)
	{
		cout<<ans[0]<<" "<<ans[i]<<"\n";
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