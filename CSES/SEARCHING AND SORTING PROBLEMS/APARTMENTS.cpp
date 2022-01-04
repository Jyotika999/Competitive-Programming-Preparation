
// Problem: Apartments
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1084
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,m,k;
	cin>>n>>m>>k;
	
	vector<ll>a(n);
	for(ll i=0;i<n;i++)
	cin>>a[i];
	
	vector<ll>b(m);
	
	for(ll j=0;j<m;j++)
	cin>>b[j];
	
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	
	ll ct=0;
	ll j=0;
	ll ans=0;
	
	for(ll i=0;i<n;i++)
	{
		while(j<m)
		{
			if(b[j]+k< a[i])
			{
				j++;
			}
			else if(b[j]-k>a[i])
			{
				break;
			}
			else
			{
				j++;
				ans++;
				break;
			}
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