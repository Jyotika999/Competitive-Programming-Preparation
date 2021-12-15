
// Problem: B. Box
// Contest: Codeforces - Technocup 2020 - Elimination Round 3
// URL: https://codeforces.com/problemset/problem/1227/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	ll ans[n];
	// memset(ans, -1, sizeof(n));
	for(ll i=0;i<n;i++)
	ans[i]=-1;
	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	set<ll>s;
	for(ll i=1;i<=n;i++)
	{
		s.insert(i);
	}
	ll flag=1;
	
	for(ll i=0;i<n;i++)
	{
		if(s.find(ar[i])!=s.end())
		{
			auto it= s.find(ar[i]);
			ans[i]=ar[i];
			s.erase(it);
		}
		
	}
// 	
	// for(auto it=s.begin(); it!=s.end();it++)
	// {
		// cout<<*it<<"\n";
	// }
	
	for(ll i=0;i<n;i++)
	{
		if(ans[i]==-1)
		{
			auto frnt= s.begin();
			// cout<<*frnt<<"\n";
			if(*frnt<=ar[i])
			{
				ans[i]=*frnt;
				s.erase(s.begin());
			}
			else
			{
				flag=0;
			}
			// cout<<ans[i]<<"\n";
		}
	}
	if(flag==0)
	{
		cout<<"-1\n";
		return;
	}
	else
	{
		for(ll i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
	}

cout<<"\n";
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