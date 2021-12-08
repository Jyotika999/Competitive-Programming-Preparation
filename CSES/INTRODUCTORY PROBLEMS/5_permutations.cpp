
// Problem: Permutations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1070
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
	
	if(n==2 || n==3)
	{
		cout<<"NO SOLUTION";
	} 
	else
	{
		vector<ll>v;
		ll i=0;
		
		for(i=2;i<=n;i+=2)
		{
			v.push_back(i);
		}
		for(i=1;i<=n;i+=2)
		{
			v.push_back(i);
		}
		for(ll i=0;i<n;i++)
		cout<<v[i]<<" ";
	}
}
int main()
{
	ll tc=1;
	// cin>>tc;
	while(tc--)
	{
		solve();
	}
}