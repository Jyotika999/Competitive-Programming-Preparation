// Problem: D. Fast search
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll lowerbound(ll val, vector<ll>&ar)
{
	ll low=0;
	ll high=ar.size()-1;
	ll ans=-1;
	while(low<=high)
	{
		ll mid =  (low+high)/2;
		
		if(ar[mid]<val)
		{
			// ans=mid;
			low=mid+1;
		}
		else if(ar[mid]>=val)
		{
			ans=mid;
			high = mid-1;
		}
		// else
		// {
			// ans= mid;
			// return ans;
		// }
	}
	
	return ans;
}
ll upperbound(ll val, vector<ll>&ar)
{
	ll low=0;
	ll high=ar.size()-1;
	ll ans=-1;
	while(low<=high)
	{
		ll mid = (low+(high-low)/2);
		if(ar[mid]<=val)
		{
			ans=mid;
			low=mid+1;
		}
		else
		{
			// ans=mid;
			high=mid-1;
		}
	}
	return ans;
}
void solve()
{
	
	ll n;
	cin>>n;
	vector<ll>ar(n);
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	sort(ar.begin(), ar.end());
	
	ll k;
	cin>>k;
	while(k--)
	{
		ll l,r;
		cin>>l>>r;
		// cout<<l<<" "<<r<<"\n";
		ll i1 = lowerbound(l, ar);
		ll i2 = upperbound(r, ar);
		// i2--;
		if(i1==-1 || i2==-1)
		cout<<"0 ";
		else {
		// cout<<i1<<" "<<i2<<" ";
		
		cout<<i2-i1+1<<" ";}
	}
	
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