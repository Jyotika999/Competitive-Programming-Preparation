
// Problem: E1. Permutation Minimization by Deque
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/E1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	deque<ll>dq;
	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		if(dq.empty())
		{
			dq.push_back(ar[i]);
		}
		else
		{
			if(dq.front() >= ar[i])
			{
				dq.push_front(ar[i]);
			}
			else
			{
				dq.push_back(ar[i]);
			}
		}
	}
	
	while(!dq.empty())
	{
		cout<<dq.front()<<" ";
		dq.pop_front();
	}
	cout<<"\n";
	
	
	
	
}
int main()
{
	ll tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}