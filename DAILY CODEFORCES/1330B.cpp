
// Problem: B. Cow and Friend
// Contest: Codeforces - Codeforces Round #621 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1307/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,x;
	cin>>n>>x;
	map<ll,ll>mp;
	double maxi=0;
	for(ll i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		maxi = max(maxi, (double)val);
		mp[val]++;
	}
	
	ll ans=0;
	if(mp[x])
	{
		ans=1;
	}
	else
	{
		maxi=maxi*1.0;
		ll t= ceil(x/maxi);
		ans= max(t, (ll)2);
	}
	cout<<ans<<"\n";
	
	
}
int main()
{
	ll tc=1;
	 cin>>tc;
	while(tc--)
	{
		solve();
	}
}