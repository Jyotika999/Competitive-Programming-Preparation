
// Problem: B. Alice and the List of Presents
// Contest: Codeforces - Codeforces Round #593 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1236/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll expo(ll a, ll b, ll mod)
{
	if(b==0)
	return 1;
	if(b==1)
	return a%mod;
	
	ll res=1;
	while(b>0)
	{
		if(b&1)
		res = ((res%mod) * (a%mod))%mod;
		b>>=1;
		a = ((a%mod) * (a%mod))%mod;
		
	}

	return res;
	
}
void solve()
{
	ll n, m;
	cin>>n>>m;
	
	ll mod = 1000000007;
	ll total_subsets = expo(2, m , mod);
	ll total_valid_subsets = total_subsets-1;
	
	ll total_gifts_distribution = expo(total_valid_subsets, n, mod);
	
	cout<<total_gifts_distribution<<"\n";
	
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