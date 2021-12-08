
// Problem: B. National Project
// Contest: Codeforces - Educational Codeforces Round 82 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1303/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,g,b;
	cin>>n>>g>>b;
	
	ll total_good=(n+1)/2;
	ll total_bad_cycles = total_good/g;
	
	if(total_good%g==0)
	total_bad_cycles--;
	
	ll ans = total_bad_cycles*b+ total_good;
	
	cout<<max(n, ans)<<"\n";
	
	
	
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