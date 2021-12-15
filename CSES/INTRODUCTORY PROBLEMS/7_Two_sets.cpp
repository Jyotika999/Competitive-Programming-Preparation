#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll sum=n*(n+1)/2;
	
	
	if(sum&1)
	{
		cout<<"NO\n";
	}
	else
	{
		ll ans=sum/2;
		vector<ll>first;
		vector<ll>second;
		for(ll i=n;i>=1;i--)
		{
			if(i<=ans)
			{
				first.push_back(i);
				ans-=i;
			}
			else
			{
				second.push_back(i);
			}
		}
		
		cout<<"YES\n";
		cout<<first.size()<<"\n";
		for(ll i=0;i<first.size();i++)
		cout<<first[i]<<" ";
		cout<<"\n";
		cout<<second.size()<<"\n";
		for(ll i=0;i<second.size();i++)
		cout<<second[i]<<" ";
		cout<<"\n";
		
		
	}
}
int main()
{
	ll tc=1;
	// cin>>tc;
	while(tc--)
	{
		solve();
	}
}