// Problem: C. Sequence Pair Weight
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1527/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n+1];
	map<ll,vector<ll>>mp;
	
	for(ll i=1;i<=n;i++)
	{
		
		cin>>ar[i];
		mp[ar[i]].push_back(i);
	}
	
	ll total=0;
	for(auto it : mp)
	{
		ll ff = it.first;
		vector<ll> ss = it.second;
		
		ll sum=0;
		for(int i=0;i<ss.size();i++)
		{
			
			total+= (sum*(n-ss[i]+1));
			sum+=ss[i];
		}
	}
	
	cout<<total<<"\n";
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