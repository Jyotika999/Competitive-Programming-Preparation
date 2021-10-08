
// Problem: Maximum Sum
// Contest: HackerEarth - Algorithms - Searching - Linear Search
// URL: https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/maximum-sum-4-f8d12458/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	sort(ar, ar+n);
	
	ll sum= 0;
	ll temp=0;
	ll ct=0;
	ll flag=1;
	for(ll i=0;i<n;i++)
	{
		if(ar[i]<0)
		{}
		else
		{sum+=ar[i]; ct++;flag=0;}
	}
	
	
	if(flag==1)
	cout<<ar[n-1]<<" "<<1<<"\n";
	else
	cout<<sum<<" "<<ct<<"\n";
	
}
int main()
{
	ll tc=1;
	//cin>>tc;
	while(tc--)
	{
		solve();
	}
}