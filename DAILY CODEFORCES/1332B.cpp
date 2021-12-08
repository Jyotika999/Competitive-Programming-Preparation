
// Problem: B. Composite Coloring
// Contest: Codeforces - Codeforces Round #630 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1332/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	map<ll,ll>mp;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	ll ct=1;
	ll prime[11]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	
	for(ll i=0;i<11;i++)
	{
		ll flag=0;
		for(ll j=0;j<n;j++)
		{
			if(ar[j]%prime[i]==0 and mp[ar[j]]==0)
			{
				flag=1;
				mp[ar[j]]=ct;
				// ct++;
			}
		}
		if(flag)
		ct++;
	}
	cout<<ct-1<<"\n";
	for(ll i=0;i<n;i++)
	cout<<mp[ar[i]]<<" ";
	cout<<"\n";
	// ll ct=1;
	// for(ll i=0;i<n;i++)
	// {
		// for(ll j=i+1;j<n;j++)
		// {
			// if(__gcd(ar[i], ar[j])>1)
			// {
				// ll f = mp[ar[i]];
				// ll s = mp[ar[j]];
// 				
				// if(f==0 and s==0)
				// {
					// mp[ar[i]]=ct;
					// mp[ar[j]]=ct;
					// ct++;
				// }
				// else if(f==s)
				// {
					// continue;
				// }
				// else
				// {
					// ll f = mp[ar[i]];
					// ll s = mp[ar[j]];
					// if(f!=0)
					// mp[ar[j]]=f;
					// else if(s!=0)
					// mp[ar[i]]=s;
					// else
					// {
						// mp[ar[i]]=ct;
						// mp[ar[j]]=ct;
						// ct++;
					// }
				// }
			// }
			// else
			// {
				// mp[ar[i]]=ct;
				// ct++;
				// mp[ar[j]]=ct;
				// ct++;
			// }
			// // cout<<ct<<"\n";
		// }
// 		
	// }
// 	
	// cout<<ct-1<<"\n";
	// for(ll i=0;i<n;i++)
	// {
		// cout<<mp[ar[i]]<<" ";
		// // cout<<ar[i]<<" "<<mp[ar[i]]<<"\n ";
	// }
	// cout<<"\n";
	
	
	
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