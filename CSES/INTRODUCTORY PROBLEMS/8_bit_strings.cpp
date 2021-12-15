#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000000007;

ll expo(ll a, ll b )
{
	if(b==0)
	return 1;
	
	if(b==1)
	return a;
	
	ll temp= expo(a, b/2);
	ll t2= ((temp%mod)*(temp%mod))%mod;
	
	if(b&1)
	{
		return ((t2%mod)*(a%mod))%mod;
	}
	else
	{
		return t2;
	}
	
}
void solve()
{
	ll n;
	cin>>n;
	
	ll ans=expo(2, n);
	cout<<ans<<"\n";
	
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