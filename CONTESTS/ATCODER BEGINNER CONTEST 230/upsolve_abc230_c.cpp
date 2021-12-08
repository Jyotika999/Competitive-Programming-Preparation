
// Problem: C - X drawing
// Contest: AtCoder - AtCoder Beginner Contest 230
// URL: https://atcoder.jp/contests/abc230/tasks/abc230_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,a,b;
	cin>>n>>a>>b;
	ll p,q,r,s;
	cin>>p>>q>>r>>s;
	
	ll start=max(p-a, r-b);
	ll end = min(q-a, s-b);
	
	string str="";
	vector<string>ans;
	for (ll i = 0; i < (s - r + 1); i++)str += '.';
	for (ll i = 0; i < (q - p + 1); i++)ans.push_back(str);

	
	for(ll i=start;i<=end;i++)
	{
		ans[a + i - p][b + i - r] = '#';
	}
	
	start = max(p - a, b - s);
	end = min(q - a, b - r);
	
	for(ll i=start;i<=end;i++)
	{
		ans[a + i - p][b - i - r] = '#';
	}
	
	for(ll i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"\n";
	}
	
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