// Problem: C - Choose Elements
// Contest: AtCoder - AtCoder Beginner Contest 245
// URL: https://atcoder.jp/contests/abc245/tasks/abc245_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll a[n];
	ll b[n];
	
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(ll j=0;j<n;j++)
	{
		cin>>b[j];
	}
	
	ll dp1[n];
	ll dp2[n];
	
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	
	dp1[0]=1;
	dp2[0]=1;
	
	for(ll i=1;i<n;i++)
	{
		if(dp1[i-1]==1)
		{
			if(abs(a[i-1]-a[i])<=k)
			{
				dp1[i]=1;
			}
			if(abs(a[i-1]-b[i])<=k)
			{
				dp2[i]=1;
			}
		}
		if(dp2[i-1]==1)
		{
			if(abs(b[i-1]-a[i])<=k)
			{
				dp1[i]=1;
			}
			if(abs(b[i-1]-b[i])<=k)
			{
				dp2[i]=1;
			}
		}
	}
	
	if(dp1[n-1]||dp2[n-1])
	cout<<"Yes\n";
	else
	cout<<"No\n";
	
	
	
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