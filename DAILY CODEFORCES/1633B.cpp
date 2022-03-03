// Problem: B. Minority
// Contest: Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1633/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string s;
	cin>>s;
	ll n= s.length();
	
	ll one[n];
	ll zero[n];
	memset(one, 0, sizeof(one));
	memset(zero, 0, sizeof(zero));
	
	if(s[0]=='1')
	one[0]=1;
	else
	zero[0]=1;
	
	for(ll i=1;i<n;i++)
	{
		if(s[i]=='1')
		{
			one[i]=one[i-1]+1;
			zero[i]=zero[i-1];
		}
		else if(s[i]=='0'){
			one[i]=one[i-1];
			zero[i]=zero[i-1]+1;
		}
		
	}
	ll ct=0;
	
	for(ll i=0;i<n;i++)
	{
		// cout<<zero[i]<<" "<<one[i]<<"\n";
		if(one[i]!=zero[i])
		ct = max(ct, min(zero[i], one[i]));
	}
	cout<<ct<<"\n";
	
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