// Problem: C. OKEA
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll ar[n+5][k+5];
	
	if(k==1)
	{
		// cout<<"YES\n";
		for(ll i=1;i<=n;i++)
		{
			ar[i][k]= i;
			// cout<<i<<"\n";
		}
		
	}
	else
	{
		//if((n*k)%2==0)
		{
			// cout<<"YES\n";
			for(ll i=1;i<=n;i++)
			{
				ll v=i;
				for(ll j=1;j<=k;j++)
				{
					ar[i][j]= v;
					// cout<<v<<" ";
					v=v+n;
				}
				// cout<<"\n";
			}
			
		}
		// else
		// {
			// // cout<<"NO\n";
			// // return;
		// }
	}
	
	ll flag=1;
	for(ll i=1;i<=n;i++)
	{
		ll par = ar[i][1]%2;
		
		for(ll j=2;j<=k;j++)
		{
			if(ar[i][j]%2 == par)
			//
			{
				
			}
			else
			flag=0;
		}
	}
	
	if(flag)
	{
		cout<<"YES\n";
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=k;j++)
			{
				cout<<ar[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else
	{
		cout<<"NO\n";
	}
// 	
	// for(ll i=1;i<=n;i++)
	// {
		// // for(ll j=1;j<=k;j++)
		// {
			// for(ll l=1;l<=k;l++)
			// {
				// for(ll r=l;r<=k;r++)
				// {
					// ll sum=0;
					// for(ll m=l;m<=r;m++)
					// {
						// sum=sum+ar[i][m];
					// }
					// if(sum%(r-l+1)==0)
					// {
						// // cout<<"sahi hai\n";
					// }
					// else
					// {
						// // cout<<i<<" ";
						// cout<<"galat hai\n";
					// }
				// }
			// }
		// }
	// }
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