
// Problem: Distinct Numbers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1621
// Memory Limit: 512 MB
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
	map<ll,ll>mp;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		// if(mp[ar[i]])
		// {
			// cout<<ar[i]<<"\n";
		// }
		mp[ar[i]]++;
		
	}
	cout<<mp.size()<<"\n";
	
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