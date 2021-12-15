
// Problem: Trailing Zeros
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1618
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
	
	ll ct=5;
	ll count=0;
	
	while((n/ct)!=0)
	{
		count+= (n/ct);
		ct*=5;
	}
	cout<<count<<"\n";
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