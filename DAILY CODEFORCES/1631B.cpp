// Problem: B. Fun with Even Subarrays
// Contest: Codeforces - Codeforces Round #768 (Div. 2)
// URL: https://codeforces.com/contest/1631/problem/B
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
	vector<ll>ar(n,0);
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	reverse(ar.begin(), ar.end());
	
	ll operation=0;
	ll flag=0;
	ll cur_len=0;
	ll cur_ele = ar[0];
	ll len=0;
	ll prev=0;
	
	while(flag==0)
	{
		
		len=0;
		for(ll i=0;i<n;i++)
		{
			if(ar[i]!=cur_ele)
			break;
			else
			len++;
		}
		
		// cout<<len<<"\n";
		if(len==n)
		break;
		
		for(ll i=len; i<=min(n-1, 2*(len)-1);i++)
		{
			ar[i]=cur_ele;
			// prev=i;
		}
		

		operation++;
	}
	
	cout<<operation<<"\n";
	
	
	
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