
// Problem: B. Combinatorics Homework
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll ar[3];
	for(ll i=0;i<3;i++)
	{
		cin>>ar[i];
	}
	ll m;
	cin>>m;
	sort(ar, ar+3);
	
	ll maxp = ar[0]-1 + ar[1] - 1 + ar[2] - 1;
	ll minp = ar[2] - ar[1] - ar[0] -1;
	
	if(m>=minp and m<=maxp)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
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