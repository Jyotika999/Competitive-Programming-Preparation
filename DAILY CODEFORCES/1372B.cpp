
// Problem: B. Omkar and Last Class of Math
// Contest: Codeforces - Codeforces Round #655 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1372/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	ll k=1;
	cin>>n;
	
	for(ll i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			k= max(k, max(i, n/i));
		}
	}
	
	// if(k==0)
	// k=n;
	
	cout<<k<<" "<<(n-k)<<"\n";
	
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