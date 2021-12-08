
// Problem: C. Labs
// Contest: Codeforces - Codeforces Round #593 (Div. 2)
// URL: https://codeforces.com/contest/1236/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	ll ar[n][n];
	ll ct=1;
	
		for(ll j=0;j<n;j++)
		{
			if(j%2==0)
			{
				for(ll i=0;i<n;i++)
	        	{
					ar[i][j]=ct;
					ct++;
			    }
			}
			else
			{
				for(ll i=n-1;i>=0;i--)
	        	{
					ar[i][j]=ct;
					ct++;
			    }
				
			}
			
	    }
	    for(ll i=0;i<n;i++)
	    {
	    	for(ll j=0;j<n;j++)
	    	{
	    		cout<<ar[i][j]<<" ";
	    	}
	    	cout<<"\n";
	    }
	// vector<vector<ll>>v(n);
	// ll ct=1;
	// while(ct<=n*n)
	// {
		// for(ll i=1;i<=n;i++)
		// {
			// v[i].push_back(ct++);
		// }
// 		
		// for(ll i=n-1;)
// 		
// 		
	// }
	
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