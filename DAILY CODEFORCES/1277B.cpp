
// Problem: B. Make Them Odd
// Contest: Codeforces - Codeforces Round #606 (Div. 2, based on Technocup 2020 Elimination Round 4)
// URL: https://codeforces.com/problemset/problem/1277/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	set<ll>s;
	ll maxi=0;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		ll ct=0;
		//cout<<ar[i]<<" ";
		while(ar[i]%2==0)
		{//ct++;
		ar[i]/=2;
		s.insert(ar[i]);
		}
	//	cout<<ct<<"\n";
		//maxi =max(maxi, ct);
	}
	cout<<s.size()<<"\n";
	
	
	
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