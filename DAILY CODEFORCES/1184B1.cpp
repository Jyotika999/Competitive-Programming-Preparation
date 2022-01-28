
// Problem: B1. The Doctor Meets Vader (Easy)
// Contest: Codeforces - Helvetic Coding Contest 2019 online mirror (teams allowed, unrated)
// URL: https://codeforces.com/problemset/problem/1184/B1
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll s, b;
	cin>>s>>b;
	
	ll spaceship[s];
	for(ll i=0;i<s;i++)
	{
		cin>>spaceship[i];
	}
	vector<pair<ll,ll>>base;
	
	for(ll i=0;i<b;i++)
	{
		ll defence, gold;
		cin>>defence>>gold;
		base.push_back({defence, gold});
	}
	sort(base.begin(), base.end());
	
	// prefix sum of gold collected till now
	
	for(ll i=1;i<b;i++)
	{
		auto prev = base[i-1].second;
		base[i].second = base[i].second + prev;
	}
	// for(ll i=0;i<b;i++)
	// {
		// cout<<base[i].first<<" "<<base[i].second<<"\n";
	// }
	
	
	
	for(ll i=0;i<s;i++)
	{
		ll cur = spaceship[i];
		ll low=0;
		ll high=b-1;
		ll index=-10000;
		while(low<=high)
		{
			ll mid = (low+(high-low)/2);
			
			if(base[mid].first<=cur)
			{
				low=mid+1;
				index=mid;
			}
			else
			{
				high=mid-1;
			}
		}
		
		if(index!=-10000)
		cout<<base[index].second<<" ";
		else
		cout<<"0 ";
		
	}
	
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