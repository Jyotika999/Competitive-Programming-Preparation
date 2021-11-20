
// Problem: C1. k-LCM (easy version)
// Contest: Codeforces - Codeforces Round #708 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1497/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,k;
	cin>>n>>k;
	
	// k=3
	if(n%4==0)
	{
		cout<<(n/2)<<" "<<(n/4)<<" "<<(n/4)<<"\n";
	}
	else if(n%3==0)
	{
		cout<<(n/3)<<" "<<(n/3)<<" "<<(n/3)<<"\n";
	}
	else if(n%2==1)
	{
		cout<<(n/2)<<" "<<1<<" "<<n/2<<"\n";
	}
	else
	{
		cout<<2<<" "<<(n/2)-1<<" "<<(n/2)-1<<"\n";
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