
// Problem: Ferris Wheel
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1090
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,x;
	cin>>n>>x;
	
	vector<ll>v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	
	ll i=0;
	ll j=n-1;
	ll ct=0;
	vector<ll>sit(n,1);
	
	while(i<j)
	{
		// pair the heaviest with the smallest
		if(v[i]+v[j]<=x)
		{
			sit[i]=0;
			sit[j]=0;
			
			i++;
			j--;
			ct++;
			
		}
		
		// else only make the heaviest sit in a gondola 
		else if(v[i]+v[j]>x)
		{
			sit[j]=0;
			j--;
			ct++;
		}
	}
	for(ll i=0;i<n;i++)
	{
			// Calculate the number of children not having gondolas yet
		// to get the total number of gondolas needed for the problem.
		ct+=sit[i];
	}
	cout<<ct<<"\n";
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