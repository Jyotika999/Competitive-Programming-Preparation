
// Problem: B - Triple Metre
// Contest: AtCoder - AtCoder Beginner Contest 230
// URL: https://atcoder.jp/contests/abc230/tasks/abc230_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string ar[3]={"oxx", "xox", "xxo"};
	
	string s;
	cin>>s;
	ll n = s.length();
	bool ok=true;
	
	for(ll j=0;j<3;j++)
	{ ok = true;
		for(ll i=0;i<n;i++)
		{
			//cout<<s[i]<<" "<<ar[j][i%3]<<"\n";
			if(s[i]!=ar[j][i%3])
			ok=false;
		}
		//cout<<"new\n";
		if(ok)
		{
			cout<<"Yes\n";
			return;
		}
	}
	
	cout<<"No\n";
	return;
}
int main()
{
	ll tc=1;
	//cin>>tc;
	while(tc--)
	{
		solve();
	}
}