
// Problem: B. Arrays Sum
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/problemset/problem/1408/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
		s.insert(ar[i]);
	}
	
	ll num  = (s.size()-1);
	ll den = (k-1);
	ll ans=0;
	
	
	if(k==1 and s.size()>1)
	{
		ans=-1;
		cout<<ans<<"\n";
		return;
	}
	else if(k==1 and s.size()==1)
	{
		cout<<"1\n";
		return;
	}
	else{
	
		if(num%den)
		{ans=num/den;
		ans++;}
		else
		ans=num/den;
	}
	if(ans<=0)
	ans=1;
	cout<<ans<<"\n";
	


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