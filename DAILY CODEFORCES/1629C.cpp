// Problem: C. Meximum Array
// Contest: Codeforces - Codeforces Round #767 (Div. 2)
// URL: https://codeforces.com/contest/1629/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	set<ll>s;
	map<ll,ll>mp;
	
	for(ll i=0;i<=n;i++)
	{
		s.insert(i);
	}
	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		mp[ar[i]]++;
		s.erase(ar[i]);
	}
	
	
	
	vector<ll>ans;
	
	ll mex = *s.begin();
	
	set<ll>temp;
	
	for(ll i=0;i<n;i++)
	{
		// cout<<ar[i]<<" "<<mex<<"\n";
		mp[ar[i]]--;
		if(ar[i]<mex)
		{
			//
			temp.insert(ar[i]);
		}
		if(mp[ar[i]]==0)
		{
			s.insert(ar[i]);
			mp.erase(ar[i]);
		}
		if(temp.size()==mex)
		{
			ans.push_back(mex);
			temp.clear();
			mex = *s.begin();	
		}
	}
	
	
	cout<<ans.size()<<"\n";
	for(ll i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	
	cout<<"\n";
	
	
	
	
	
	
	
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