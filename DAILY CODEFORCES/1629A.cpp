// Problem: A. Download More RAM
// Contest: Codeforces - Codeforces Round #767 (Div. 2)
// URL: https://codeforces.com/contest/1629/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,k;
	cin>>n>>k;
	vector<ll>a(n);
	vector<ll>b(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
	}
	vector<pair<ll,ll>>v;
	
	for(ll i=0;i<n;i++)
	{
		v.push_back({a[i], b[i]});
	}
	sort(v.begin(), v.end());
	
	for(ll i=0;i<n;i++)
	{
		if(v[i].first<=k)
		{
			k+=v[i].second;
		}
		else
		{
			break;
		}
	}
	
	cout<<k<<"\n";
	
	
	
	
}
int main()
{
	ll tc=1;
	cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}