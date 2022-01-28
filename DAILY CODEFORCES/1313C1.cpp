
// Problem: C1. Skyscrapers (easy version)
// Contest: Codeforces - Codeforces Round #622 (Div. 2)
// URL: https://codeforces.com/contest/1313/problem/C1
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	vector<ll>ar(n);
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	ll maxsum=0;
	
	vector<ll>ans(n);
	
	for(ll i=0;i<n;i++)
	{
		ll cur=ar[i];
		vector<ll>temp(n);
		// leftsum
		ll leftsum=0;
		temp[i]=ar[i];
		for(ll j=i-1;j>=0;j--)
		{
			cur=min(cur, ar[j]);
			leftsum+=cur;
			temp[j]=cur;
		}
		
		
		cur=ar[i];
		ll rightsum=0;
		// rightsum
		for(ll j=i+1;j<n;j++)
		{
			cur=min(cur, ar[j]);
			rightsum+=cur;
			temp[j]=cur;
		}
		
		ll cursum = ar[i]+leftsum+rightsum;
		if(cursum>maxsum)
		{
			maxsum = cursum;
			ans=temp;
		}
		
	}
	// ans=ar;
	for(int i=0;i<n;i++)
	cout<<ans[i]<<" ";
	
	cout<<"\n";
	
	
	
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