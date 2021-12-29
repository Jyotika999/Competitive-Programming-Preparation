
// traverse through letters of s 
// ch = current letter of s 

// for all characters present in f
//     minimum operation
//     if(ch already presnt in f)
//     continue
//     else
//         check clockwise 
//         check anticlockwise
        
// O(T*N(S)*N(F))

// Problem: Task
// Contest: Google Coding Competitions - Round H 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008da461#problem
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// Problem: Task
// Contest: Google Coding Competitions - Round H 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008da461#problem
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string s,f;
	
	cin>>s;
	cin>>f;
	
	ll ns = s.length();
	ll nf = f.length();
	ll ct=0;
	
	for(ll i=0;i<ns;i++)
	{
		char ch=s[i];
		ll temp=INT_MAX;
		for(ll j=0;j<nf;j++)
		{
			ll clockW = abs(s[i]-f[j]);
			ll anti  = 26-abs(s[i]-f[j]);
			temp=min(temp, min(clockW, anti));
		}
		if(temp!=INT_MAX)
		ct+=temp;
	}
	cout<<ct<<"\n";
	
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