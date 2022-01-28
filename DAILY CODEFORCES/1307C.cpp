
// Problem: C. Cow and Message
// Contest: Codeforces - Codeforces Round #621 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1307/C
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
	map<char,ll>mp;
	ll n = s.length();
	
	for(ll i=0;i<n;i++)
	{
		mp[s[i]-'a']++;
	}
	ll maxi=0;
	
	for(auto it : mp)
	{
		// cout<<it.first<<" "<<it.second<<"\n";
		maxi=max(maxi, it.second);
	}
	
	mp.clear();
	ll length2[26][28];
	memset(length2 ,0, sizeof(length2));
	
	for(ll i=0;i<n;i++)
	{
		// mp[s[i]]++;
		char ch = s[i]-'a';
		
		for(ll j=0;j<26;j++)
		{
			// fixing the ith character
			// checking number of occurences of j that came before it
			length2[ch][j]+=mp[j];
			// cout<<i<<" "<<j<<" "<<length2[ch][j]<<"\n";
			maxi = max(maxi, length2[ch][j]);
		}
		mp[ch]++;
		
	}
	
	// for(auto i : mp)
	// {
		// for(auto j : mp)
		// {
			// if(i.first != j.first)
			// {
				// // if we are considering strings of length = 2,
				// // this means that we also need to check if they occur in AP or not
// 				
				// ll cur = i.second*j.second;
				// maxi = max(maxi, cur);
			// }
		// }
	// }
	cout<<maxi<<"\n";
	
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
