
// Problem: C. ABBB
// Contest: Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1428/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	//"AB" or "BB".
	string s;
	cin>>s;
	ll n = s.length();
	stack<char>ch;
	ll ct=0;
	
	for(ll i=0;i<n;i++)
	{
		if(ch.empty())
		{
			ch.push(s[i]);
		}
		else
		{
			if(s[i]=='B')
			{
				if(ch.top()=='A'||ch.top()=='B')
				{
					ch.pop();
					//ct++;
				}
				else
				{
					ch.push(s[i]);
				}
			}
			else
			{
				ch.push(s[i]);
			}
		}
	}
	cout<<ch.size()<<"\n";
	
	
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