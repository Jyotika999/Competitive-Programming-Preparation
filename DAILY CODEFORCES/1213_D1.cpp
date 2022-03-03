// Problem: D1. Equalizing by Division (easy version)
// Contest: Codeforces - Codeforces Round #582 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1213/D1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll ar[n];
	set<ll>s;
	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		ll org = ar[i];
		
		while(org)
		{
			// cout<<org<<"\n";
			s.insert(org);
			org/=2;
		}
	}
	map<ll, priority_queue<ll, vector<ll>, greater<ll>>>mp;
	ll mini=INT_MAX;
	
	for(auto it = s.begin(); it!=s.end() ; it++)
	{
		
		for(ll i=0;i<n;i++)
		{
			ll operation =0 ;
			ll cur = ar[i];
			while(cur>*it)
			{
				operation++;
				cur/=2;
			}
			if(cur== *it)
			mp[*it].push(operation);
		}
		
		if(mp[*it].size()>=k)
		{
			ll cur=0;
			ll ct=0;
			while(!mp[*it].empty()  and ct<k)
			{
				cur+= mp[*it].top();
				ct++;
				mp[*it].pop();
			}
			mini = min(mini, cur);
		}
		
		
	}
	
	// for(auto it = s.begin();it!=s.end();it++)
	// {
		// ll operation=0;
		// // cout<<*it<<" ";
		// for(ll i=0;i<n;i++)
		// {
			// ll cur = ar[i];
			// if(cur<= *it)
			// operation = 0;
			// if(cur>*it)
			// {
				// while(cur>*it)
				// {
// 					
					// cur/=2;
					// operation++;
				// }
				// // if(mp[*it].size()<k)
// 				
				// // else if(mp[*it].size()==k)
				// // {
					// // if(mp[*it].top()> operation)
					// // {
						// // mp[*it].pop();
						// // mp[*it].push(operation);
					// // }
				// // }
			// }
			// if(cur==*it)
				// {mp[*it].push(operation);
				// cout<<operation<<"\n";}
		// }
		// cout<<"\n\n";
		// // if(mp[*it].size()==k)
		// if(mp[*it].size()>=k)
		// {
			// ll cur=0;
			// ll flag=0;
			// // cout<<*it<<"\n";
			// while(!mp[*it].empty() and flag<k)
			// {
				// flag++;
				// // cout<<mp[*it].top()<<" ";
				// cur+= mp[*it].top();
				// mp[*it].pop();
			// }
			// // cout<<*it<<" "<<cur<<" "<<mini<<"\n";
			// // if(flag)
			 // // cout<<"\n";
			// mini = min(mini, cur);
// 			
		// }
		// // cout<<"\n";
	// }
	
	cout<<mini<<"\n";
	
	
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