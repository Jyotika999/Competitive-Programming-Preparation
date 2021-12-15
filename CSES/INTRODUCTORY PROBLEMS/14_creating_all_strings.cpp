
// Problem: Creating Strings
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1622
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
set<string>Ans;

void permute(string a,  ll l, ll r)
{
	if(l==r)
	{
		Ans.insert(a);
		
		// cout<<a<<"\n";
		return;
	}
	
	for(ll i=l;i<=r;i++)
	{
		// swap
		swap(a[l], a[i]);
		
		// permute
		permute(a, l+1, r);
		
		// reswap
		swap(a[l], a[i]);
	}
	
}
void solve()
{
	string s;
	cin>>s;
	ll n=s.length();
	sort(s.begin(), s.end());
	permute(s, 0, n-1);
	
	cout<<Ans.size()<<"\n";
	
	for(auto it=Ans.begin();it!=Ans.end();it++)
	cout<<*it<<"\n";
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