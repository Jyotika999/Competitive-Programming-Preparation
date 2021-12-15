
// Problem: A. Life of a Flower
// Contest: Codeforces - Codeforces Round #759 (Div. 2, based on Technocup 2022 Elimination Round 3)
// URL: https://codeforces.com/contest/1591/problem/A
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
	ll len=1;
	ll prev=0;
	// ll ans=0;
	for(ll i=0;i<n;i++)
	cin>>ar[i];
	
	
	for(ll i=0;i<n;i++)
	{
		if(ar[i]==0)
		{
			if(i>=1 and ar[i-1]==0)
			{
				len=-1;
				break;
			}
			else
			{
				continue;
			}
		}
		else if(ar[i]==1)
		{
			if(i>=1 and ar[i-1]==1)
			{
				len+=5;
			}
			else
			{
				len++;
			}
		}
		
		// cout<<len
	}
	
	cout<<len<<"\n";
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