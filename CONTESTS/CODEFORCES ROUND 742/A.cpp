
// Problem: A. Domino Disaster
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	//cout<<s<<"\n";
	
	//vector<char>ans;
	
	for(int i=0;i<s.length();i++)
	{
		//cout<<s[i];
		 if(s[i]=='L' || s[i]=='R')
		cout<<s[i];
		else if(s[i]=='D')
		cout<<"U";
		else
		cout<<"D";
		//cout<<s[i]<<" ";
		
	}
	cout<<"\n";
	// for(int i=0;i<n;i++)
	// cout<<ans[i];
	//cout<<ans<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}