// Problem: A. Linear Keyboard
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1607/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string key;
	cin>>key;
	
	string s;
	cin>>s;
	ll n = key.length();
	
	unordered_map<ll,ll>mp;
	
	for(ll i=0;i<n;i++)
	{
		mp[key[i]]=i+1;
	}
	
	ll ns = s.length();
	ll ct=0;
	
	for(ll i=1;i<ns;i++)
	{
		char ff = s[i];
		char ss = s[i-1];
		ct+= abs(mp[ff]-mp[ss]);
	}
	cout<<ct<<"\n";
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