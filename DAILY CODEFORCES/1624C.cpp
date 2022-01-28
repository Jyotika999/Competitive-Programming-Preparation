
// Problem: C. Division by Two and Permutation
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1624/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	ll vis[n+1];
	memset(vis, 0, sizeof(vis));
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		// vis[ar[i]]=1;
	}
	
	sort(ar, ar+n);
	for(ll i=0;i<n;i++)
	{
		ll cur=ar[i];
		// cout<<cur<<"\n";
		while(cur>n || vis[cur]==1)
		{
			cur/=2;
			if(cur==0)
			break;
		}
		if(cur!=0)
		vis[cur]=1;
	}
	
	for(ll i=1;i<=n;i++)
	{
		// cout<<
		if(vis[i])
		continue;
		else
		{
			cout<<"NO\n";
			return;
		}
	}
	
	cout<<"YES\n";
	
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