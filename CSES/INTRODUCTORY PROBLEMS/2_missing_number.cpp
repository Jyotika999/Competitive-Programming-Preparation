
// Problem: Missing Number
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1083
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
	ll sum=0;
	for(ll i=0;i<n-1;i++)
	{
		ll val;
		cin>>val;
		sum+=val;
	}
	ll missing = n*(n+1)/2 - sum;
	cout<<missing<<"\n";
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