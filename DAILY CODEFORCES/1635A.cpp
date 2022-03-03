// Problem: A. Min Or Sum
// Contest: Codeforces - Codeforces Round #772 (Div. 2)
// URL: https://codeforces.com/contest/1635/problem/A
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
	ll ar[n];
	for(ll i=0;i<n;i++)
	cin>>ar[i];
	
	ll bit[32]={0};
	
	for(ll i=0;i<n;i++)
	{
		ll cur = ar[i];
		for(ll j=0;j<32;j++)
		{
			if((cur>>j) & (1))
			{
				bit[j]=1;
			}
		}
	}
	
	ll ans=0;
	for(ll i=0;i<32;i++)
	{
		// cout<<i<<" "<<bit[i]<<"\n";
		if(bit[i]==1)
		{
			ans+= pow(2,i);
		}
	}
	cout<<ans<<"\n";
	
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