// Problem: C. Andrew and Stones
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/C
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
	// priority_queue<ll>even;
	// prority_queue<ll>odd;
	ll even=0;
	
	ll flag=0;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		if(i>0 and i<n-1)
		{
			if(ar[i]>1)
			flag=1;
			if(ar[i]%2==0)
			even++;
		// if(ar[i]&1)
		// odd.push(ar[i]);
		// else if(ar[i]%2==0 and ar[i]!=0)
		// even.push(ar[i]);
		}
	}
	
	if(flag==0)
	{
		cout<<"-1\n";
	}
	else if(even==0 and n==3)
	{
		cout<<"-1\n";
	}
	else
	{
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			if(i>0 and i<n-1)
			{
				if(ar[i]%2==0)
				{
					ans+= ar[i]/2;
				}
				else
				{
					ans+= (ar[i]+1)/2;
				}
			}
		}
		cout<<ans<<"\n";
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
