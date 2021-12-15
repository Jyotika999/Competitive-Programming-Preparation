
// Problem: Gray Code
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2205
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<string> gray_code(ll n)
{
	if(n==0)
	{
		vector<string>v;
		v.push_back("0");
		v.push_back("1");
		return v;
	}
	
	vector<string> res = gray_code(n-1);
	
	vector<string>v;
	ll res_n = res.size();
	for(ll i=0;i<res_n;i++)
	{
		string s="0"+res[i];
		v.push_back(s);
	}
	
	// isse consecutive ka hamming distance 1 nhi ayega 
	// for(ll i=0;i<=res_n-1;i++)
	// {
		// string s="1"+res[i];
		// v.push_back(s);
	// }
	
	for(ll i=res_n-1;i>=0;i--)
	{
		string s="1"+res[i];
		v.push_back(s);
	}
	
	return v;
	
	
	
	
}
void solve()
{
	ll n;
	cin>>n;
	n--;
	vector<string> v = gray_code(n);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\n";
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