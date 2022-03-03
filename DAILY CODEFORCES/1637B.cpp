// Problem: B. MEX and Array
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/B#
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	vector<ll>v(n,0);
	
	for(ll i=0;i<n;i++)
	cin>>v[i];
	
	ll sum=0;
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			ll ct = j-i;
			for(ll k=i;k<j;k++)
			{
				// cout<<v[k]<<" ";
				if(v[k]==0)
				ct++;
			}
			// cout<<"\n";
			sum+=ct;
		}
	}
	cout<<sum<<"\n";
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