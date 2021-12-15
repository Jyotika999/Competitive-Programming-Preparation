
// Problem: Palindrome Reorder
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1755
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
	ll even=0;
	ll odd=0;
	ll n=s.length();
	map<char, ll>mp;
	
	for(ll i=0;i<n;i++)
	{
		mp[s[i]]++;
	}
	char odd_ch='*';
	for(auto it : mp)
	{
		if(it.second&1)
		{odd++;
		odd_ch=it.first;}
		else
		even++;
	}
	
	if(odd==0 || odd==1)
	{
		// solution exists
		string frnt="";
		string back="";
		for(auto it : mp)
		{
			if(it.first!=odd_ch)
			{
			int ct=it.second;
			ct/=2;
			for(int i=0;i<ct;i++)
			{
				frnt+=it.first;
			}
			}
		}
		for(auto it : mp)
		{
			if(it.first!=odd_ch)
			{
				int ct=it.second;
				ct/=2;
				ct=it.second-ct;
				for(int i=0;i<ct;i++)
				{
					back+=it.first;
				}
			}
		}
		
		reverse(back.begin(), back.end());
		string odd_str="";
		for(ll i=0;i<mp[odd_ch];i++)
		odd_str+=odd_ch;
		if(odd_ch!='*')
		cout<<frnt+odd_str+back<<"\n";
		else
		cout<<frnt+back<<"\n";
	}
	else
	{
		// no solution 
		cout<<"NO SOLUTION\n";
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