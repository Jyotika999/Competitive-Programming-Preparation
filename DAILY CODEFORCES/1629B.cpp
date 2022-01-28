// Problem: B. GCD Arrays
// Contest: Codeforces - Codeforces Round #767 (Div. 2)
// URL: https://codeforces.com/contest/1629/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll l,r,k;
	cin>>l>>r>>k;
	
	ll total = r-l+1;
	ll even=0;
	ll odd=0;
	
	if(total%2==0)
	{
		even = total/2;
		odd = total/2;
	}
	else
	{
		if(l&1 || r&1)
		{
			odd = total/2 +1;
			even = total-odd;
		}
		else
		{
			odd = total/2;
			even = total-odd;
		}
	}

	if(odd==1 and even==0)
	{
		if(l>1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
		
	}
	else if(odd<=k)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	// cout<<even<<" "<<odd<<"\n";
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
