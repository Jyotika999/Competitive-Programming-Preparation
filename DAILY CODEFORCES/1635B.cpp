// Problem: B. Avoid Local Maximums
// Contest: Codeforces - Codeforces Round #772 (Div. 2)
// URL: https://codeforces.com/contest/1635/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n+1];
	ll ct=0;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];	
	}
	ar[n]=-1*1e18;
	for(ll i=1;i<n-1;i++)
	{
		if(ar[i]>ar[i-1] and ar[i]>ar[i+1])
		{
			// if(i+2<n)
			ar[i+1]= max(ar[i], ar[i+2]);
			ct++;
		}
	}
	cout<<ct<<"\n";
	for(ll i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<"\n";
	
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