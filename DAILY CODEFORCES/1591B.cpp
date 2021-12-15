
// Problem: B. Array Eversion
// Contest: Codeforces - Codeforces Round #759 (Div. 2, based on Technocup 2022 Elimination Round 3)
// URL: https://codeforces.com/contest/1591/problem/B
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
	ll ar[n];
	ll maxi=0;
	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		maxi = max(maxi, ar[i]);
	}
	ll k=0;
	ll end_ele=0;
	
	
	for(ll i=n-1;i>=0;i--)
	{
		if(ar[i]==maxi)
		{
			break;
		}
		else
		{
			if(ar[i]>end_ele)
			{
				end_ele=ar[i];
				k++;
			}
		}
	}
	cout<<k<<"\n";

}
int main()
{
	ll tc=1;
	 cin>>tc;
	while(tc--)
	{
		solve();
	}
}