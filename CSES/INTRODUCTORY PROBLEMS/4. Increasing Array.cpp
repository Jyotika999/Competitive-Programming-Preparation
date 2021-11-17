// YOU WILL NEVER REGRET WORKING HARD

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n;
	cin>>n;
	ll ar[n];
	
	for(ll i=0;i<n;i++)cin>>ar[i];
	
	ll ans=0;
	
	for(ll i=1;i<n;i++)
	{
	  if(ar[i]>=ar[i-1])continue;
	  else {
	  	ans= ans + (ar[i-1]-ar[i]);
	 	ar[i] = ar[i-1];
	  }	
	}
	
	
	cout<<ans<<"\n";
	
}