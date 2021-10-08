
// Problem: A. Regular Bracket Sequences
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void print(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"(";
	}
	for(int i=1;i<=n;i++)
	{
		cout<<")";
	}
}
void solve()
{
	ll n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		print(i);
		print(n-i);
		cout<<"\n";
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