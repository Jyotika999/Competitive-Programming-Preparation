
// Problem: D. Secret Passwords
// Contest: Codeforces - Codeforces Round #603 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1263/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>graph[200005];
ll parent[200005];
ll r[200005];

ll find_parent(int i)
{
	if(i==parent[i])
	{
		return i;
	}
	return parent[i]=find_parent(parent[i]);
	
}
void unionn(ll a, ll b)
{
	a = find_parent(a);
	b = find_parent(b);
	if(a!=b)
	{
		if(r[a]==r[b])
		{
			r[a]++;
			parent[a]=b;
		}
		else if(r[a]<r[b])
		{
			// attach a to b
			parent[a]=b;
		}
		else
		{
			// attach  b to a
			parent[b]=a;
		}
	}
}


void solve()
{
	ll n;
	cin>>n;
	string s[n+1];
	// even if strings are given, no worries at all, 
	// take them as indexes when you are coming up with a graph problem
	
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i];
		parent[i]=i;
		r[i]=0;
		for(ll j=0;j<s[i].length();j++)
		{
			ll cur= s[i][j]-'a';
			graph[cur].push_back(i);
		}
	}
	
	for(ll i=0;i<26;i++)
	{
		vector<ll> g = graph[i];
		if(g.size()!=0)
		{
			// string prev = g[0];
			for(ll j=1;j<g.size();j++)
			{
				unionn(g[j-1], g[j]);
				
			}
		}
		
		
	}
	
	ll ct=0;
	for(ll i=1;i<=n;i++)
	{
		if(parent[i]==i)
		{
			ct++;
		}
	}
	cout<<ct<<"\n";
	
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