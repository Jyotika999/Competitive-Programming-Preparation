
// Problem: B. Shifting Sort
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void shift(vector<ll>&v, ll i, ll j)
{
	ll val = v[i];
	for(ll k=j;k>i;k--){
		v[k] = v[k-1];
	}
	v[i] = v[j];
}

void find_sort(vector<vector<ll>>&ans, vector<ll>v , int n)
{
	vector<ll>b(v.begin(), v.end());
	
	sort(b.begin(), b.end());
	
	ll maxval=0;
	ll maxind=0;
	for(ll i=0;i<n;i++)
	{
		maxval=0;
		maxind=0;
		
		if(v[i]==b[i])
		continue;
		else
		{
			// for(ll j=i+1;j<n-i;j++)
			// {
				// if(v[j] > maxval)
				// {
					// maxval = v[j];
					// maxind = j;
				// }
			// }
			int j=i+1;
			while(v[j]!=b[i]){
				j++;
			}
			ans.push_back({i+1, j+1, j-i});
			shift(v, i, j);
		}
	}
	
	
}
void solve()
{
	vector<ll>v;
	ll n;
	cin>>n;
	vector<vector<ll>>ans;
	
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		v.push_back(x);
	}
	
	find_sort(ans, v, n);
	
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
	}
	
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