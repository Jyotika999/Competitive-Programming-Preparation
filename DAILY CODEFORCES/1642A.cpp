// Problem: A. Hard Way
// Contest: Codeforces - Codeforces Round #773 (Div. 2)
// URL: https://codeforces.com/contest/1642/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll x1,y1, x2, y2, x3, y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	
	ll ans=0;
	if(y1==y2 and y1>y3)
	{
		ans+= abs(x1-x2);
	}
	else if(y1==y3 and y3>y2)
	{
		ans+=abs(x1-x3);
	}
	else if(y2==y3 and y2>y1)
	{
		ans+=abs(x2-x3);
	}
	cout<<ans<<"\n";
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