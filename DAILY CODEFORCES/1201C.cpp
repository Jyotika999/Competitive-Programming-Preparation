
// Problem: C. Maximum Median
// Contest: Codeforces - Codeforces Round #577 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1201/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll count(ll ar[], ll n, ll thresh)
{
	ll ct=0;
	for(ll i=n/2;i<n;i++)
	{
		if(ar[i]<thresh)
		{
			ct+=thresh-ar[i];
		}
	}
	return ct;
}
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll ar[n];
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	sort(ar, ar+n);
	
	ll low=0, high=1e12;
	ll ans=0;
	while(low<=high)
	{
		ll mid=(low+high)/2;
		
		if(count(ar, n, mid)<=k)
		{
			ans=mid;
			low=mid+1;
			
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<ans<<"\n";
	
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