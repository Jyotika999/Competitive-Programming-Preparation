// Problem: A. Sorting Parts
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/0
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
	vector<ll>v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector<ll>temp(v.begin(), v.end());
	sort(temp.begin(), temp.end());
	if(temp==v)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
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