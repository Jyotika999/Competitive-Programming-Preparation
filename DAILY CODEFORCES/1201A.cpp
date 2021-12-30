
// Problem: A. Important Exam
// Contest: Codeforces - Codeforces Round #577 (Div. 2)
// URL: https://codeforces.com/contest/1201/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// question is ki konsa option sahi hoga , toh maximum marks milenge
// for that , check kro ki current question mein jo jo option hai, 
// un sab options mein se maximum makrs kis option kai h?
// bus us option ki total value, add kroge total value mien


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n, m;
	cin>>n>>m;
	
	string s[n];
	for(ll i=0;i<n;i++)
	{
		cin>>s[i];
	}
	
	ll ar[m];
	map<char,ll>mp;
	for(ll i=0;i<m;i++)
	{
		cin>>ar[i];
		mp[i+'A']=ar[i];
	}
	
	ll total=0;
	
	// ith ques jth student
	
	map<char, ll>cnt;
	
	for(ll i=0;i<m;i++)
	{
		ll cur=0;
		for(ll j=0;j<n;j++)
		{
			cnt[s[j][i]]++;
			cur=max(cur, cnt[s[j][i]]);	
		}
		// cout<<cur<<"\n";
		cnt.clear();
		// cout<<cur<<" ";
		cur=cur*ar[i];
		// cout<<cur<<"\n";
		total+=cur;
	}
	
	cout<<total<<"\n";
	
	
}
int main()
{
	ll tc=1;
	// cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}