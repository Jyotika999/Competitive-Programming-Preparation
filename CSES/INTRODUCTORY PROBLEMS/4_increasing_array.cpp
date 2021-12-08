
// Problem: Increasing Array
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1094
// Memory Limit: 512 MB
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
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	for(ll i=1;i<n;i++)
	{
		if(ar[i]<ar[i-1])
		{
			sum+=(ar[i-1]-ar[i]);
			ar[i]=ar[i-1];
		}
		
	}
	cout<<sum<<"\n";
}
int main()
{
	ll tc=1;
	// cin>>tc;
	while(tc--)
	{
		solve();
	}
}