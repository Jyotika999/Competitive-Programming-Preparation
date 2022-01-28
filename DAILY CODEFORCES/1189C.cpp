
// Problem: C. Candies!
// Contest: Codeforces - Codeforces Round #572 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1189/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	ll pre[n+1];
	memset(pre, 0, sizeof(pre));
	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	// pre[]=ar[0];
	for(ll i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+ar[i-1];
	}
	
	ll q;
	cin>>q;
	while(q--)
	{
		ll l, r;
		cin>>l>>r;
		
			ll ct = (pre[r]-pre[l-1])/10;
			cout<<ct<<"\n";
		
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