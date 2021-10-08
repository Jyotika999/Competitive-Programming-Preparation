
// Problem: Casimir's String Solitaire
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1579/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string s;
	cin>>s;
	
	ll a=0, b=0, c=0;
	ll n = s.length();
	
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='A')
		a++;
		else if(s[i]=='B')
		b++;
		else
		c++;
	}
	
	ll min1 = min(b, c);
	b = b- min1;
	c = c- min1;
	
	ll min2 = min(a, b);
	b = b - min2;
	a = a - min2;
	
	if(a!=0 || b!=0 || c!=0)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
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