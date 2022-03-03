// Problem: B. Fortune Telling
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,x,y;
	cin>>n>>x>>y;
	
	ll ar[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		sum+=ar[i];
	}
	
	if(sum%2==0 and y%2==0)
	{
		if(x%2==0)
		{
			cout<<"Alice\n";
		}
		else
		{
			cout<<"Bob\n";
		}
	}
	else if(sum%2==0 and y%2==1)
	{
		if(x%2==1)
		{
			cout<<"Alice\n";
		}
		else
		{
			cout<<"Bob\n";
		}
	}
	else if(sum%2==1 and y%2==1)
	{
		if(x%2==0)
		{
			cout<<"Alice\n";
		}
		else
		{
			cout<<"Bob\n";
		}
	}
	else if(sum%2==1 and y%2==0)
	{
		if(x%2==1)
		{
			cout<<"Alice\n";
		}
		else
		{
			cout<<"Bob\n";
		}
	}
	
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