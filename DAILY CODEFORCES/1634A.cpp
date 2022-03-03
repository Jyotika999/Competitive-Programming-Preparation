// Problem: A. Reverse and Concatenate
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<string>v;
	v.push_back(s);
	set<string>con;
	
	if(k==0)
	{
		cout<<1<<"\n";
		return;
	}
	
		vector<string>temp;
		
		for(int i=0;i<v.size() and k>=1;i++,k--)
		{
			string str = v[i];
			string revstr = str;
			reverse(str.begin(), str.end());
			temp.push_back(str+revstr);
			con.insert(str+revstr);
			if(k)
			{
			temp.push_back(revstr+str);
			con.insert(revstr+str);
			}
		}
		v = temp;
	
	
	
	cout<<con.size()<<"\n";
	
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