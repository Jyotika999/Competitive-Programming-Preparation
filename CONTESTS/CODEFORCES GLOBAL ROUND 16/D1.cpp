
// Problem: D1. Seating Arrangements (easy version)
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/D1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,m;
	cin>>n>>m;
	
	ll ar[m];
	ll ct[m];
	
	memset(ct, 0, sizeof(ct));
	ll ans=0;
	
	for(ll i=0;i<m;i++)
	{
		cin>>ar[i];
	}
	
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<i;j++)
		{
			if(ar[j]<ar[i])
			ct[i]++;
		}
		//cout<<i<<" "<<ct[i]<<"\n";
		ans+= ct[i];
	}
	cout<<ans<<"\n";
}
int main()
{
	ll tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}