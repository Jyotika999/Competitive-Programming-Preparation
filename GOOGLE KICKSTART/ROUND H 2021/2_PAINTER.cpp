
// Problem: Task
// Contest: Google Coding Competitions - Round H 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d9a88#analysis
// Memory Limit: 1024 MB
// Time Limit: 30000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	
	// Red + Yellow = Orange
	// Red + Blue = Purple
	// Yellow + Blue = Green
	// Red + Yellow + Blue = Gray
	
	map<char,string>mp;
	mp['O']="RY";
	mp['P']="RB";
	mp['G']="YB";
	mp['A']="RYB";
	mp['R']="R";
	mp['Y']="Y";
	mp['B']="B";
	mp['U']="";
	
	
	// total minimum strokes required = minimum(RED)+minimum(YELLOW)+minimum(BLUE)

	ll r=0, y=0, b=0;
	// red stroke k liye
	ll lastpos=-1;
	for(ll i=0;i<n;i++)
	{
		char ch=s[i];
		
		if(find(mp[ch].begin(), mp[ch].end(),'R')!=mp[ch].end())
		{
			// so , we need to include it in the current stroke
			lastpos=i;
		}
		else
		{
			// continue
			if(lastpos!=-1)
			{
				r++;
				lastpos=-1;
			}
		}
	}
	if(lastpos!=-1)
	r++;
	lastpos=-1;
	
	// yellow stroke k liye
	for(ll i=0;i<n;i++)
	{
		char ch=s[i];
		
		if(find(mp[ch].begin(), mp[ch].end(),'Y')!=mp[ch].end())
		{
			// so , we need to include it in the current stroke
			lastpos=i;
		}
		else
		{
			// continue
			if(lastpos!=-1)
			{
				y++;
				lastpos=-1;
			}
		}
	}
	if(lastpos!=-1)
	y++;
	lastpos=-1;
	
	// blue stroke k liye
	for(ll i=0;i<n;i++)
	{
		char ch=s[i];
		
		if(find(mp[ch].begin(), mp[ch].end(),'B')!=mp[ch].end())
		{
			// so , we need to include it in the current stroke
			lastpos=i;
		}
		else
		{
			// continue
			if(lastpos!=-1)
			{
				b++;
				lastpos=-1;
			}
		}
	}
	if(lastpos!=-1)
	b++;
	
	// cout<<r<<" "<<y<<" "<<b<<"\n";
	cout<<r+y+b<<"\n";
	
	
}
int main()
{
	ll tc=1;
	cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}