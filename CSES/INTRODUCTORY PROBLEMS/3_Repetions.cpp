
// Problem: Repetitions
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1069
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// Problem: Missing Number
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1083
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string s;
	cin>>s;
	
	ll ct=1;
	ll maxcnt=1;
	
	for(ll i=1;i<s.length();i++)
	{
		if(s[i]==s[i-1])
		ct++;
		else
		ct=1;
		
		maxcnt= max(maxcnt, ct);
	}
	cout<<maxcnt<<"\n";
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