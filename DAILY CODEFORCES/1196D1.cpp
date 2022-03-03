// Problem: D1. RGB Substring (easy version)
// Contest: Codeforces - Codeforces Round #575 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1196/D1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

char match[3] ={'R', 'G', 'B'};

ll find_removal(string str)
{
	ll mincnt = INT_MAX;
	for(ll j=0;j<3;j++)
	{
		ll ind = j;
		ll ct=0;
		for(ll i=0;i<str.length();i++)
		{
			if(str[i]!=match[(ind)%3])
			{
				ct++;
				ind++;
			}
			else
			{
				ind++;
				// continue;
			}
		}
		mincnt = min(mincnt, ct);
	}
	 // cout<<str<<" "<<ct<<"\n";
	return mincnt;
	
}
void solve()
{
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll mincnt=INT_MAX;
	
	for(ll i=0;i<n-k+1;i++)
	{
		
		{
			string str = s.substr(i, k);
			// cout<<i<<" "<<i+k<<" "<<str<<" ";
			ll temp= find_removal(str);
			mincnt = min(mincnt, temp);
			// cout<<temp<<"  "<<str.length()<<"\n";
		}
	}
	cout<<mincnt<<"\n";
	
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