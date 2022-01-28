
// Problem: A. Not Shading
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll minii(ll a, ll b, ll c, ll d)
{
	return min(min(a, b), min(c,d));
}
void solve()
{
	ll n,m,r, c;
	cin>>n>>m>>r>>c;
	vector<ll>row;
	vector<ll>col;
	char ar[n][m];
	r--;
	c--;
	ll flag=0;
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>ar[i][j];
			if(ar[i][j]=='B')
			{
				row.push_back(i);
				col.push_back(j);
				flag=1;
			}
		
		}
	}
	
	if(flag==0)
	{
		cout<<"-1\n";
		return;
	}
	
	if(ar[r][c]=='B')
	{
		cout<<"0\n";
		return;
	}
	
	
	
	if(find(row.begin(), row.end(), r)!=row.end())
	{
		cout<<"1\n";
		return;
	}
	if(find(col.begin(), col.end(), c)!=col.end())
	{
		cout<<"1\n";
		return;
	}
	
	cout<<"2\n";
	return;
// 	
	// auto it_r = lower_bound(row.begin(), row.end(), r);
	// auto it_c = lower_bound(col.begin(), col.end(), c);
	// auto it1_r = upper_bound(row.begin(), row.end(), r);
	// auto it1_c = upper_bound(col.begin(), col.end(), c);
// 	
// 	
	// cout<<it_r-row.begin()<<"\n";
	// ll prev_r = INT_MAX;
	// ll prev_c = INT_MAX;
	// ll next_r = INT_MAX;
	// ll next_c = INT_MAX;
	// ll mini = INT_MAX;
	// for(ll i=0;i<n;i++)
	// {
		// for(ll j=0;j<m;j++)
		// {
			// if(ar[i][j]=='B')
			// {
				// mini = min(mini, min(abs(r-i), abs(j-c))+1);
			// }
		// }
	// }
	// cout<<mini<<"\n";
// 	
	// if(it_r != row.end())
	// {
		// prev_r = it_r-row.begin();
	// }
	// if(it_c!=col.end())
	// {
		// prev_c = it_c-col.begin();
	// }
	// if(it1_r != row.end())
	// {
		// next_r = it1_r-row.begin();
	// }
	// if(it1_c!=col.end())
	// {
		// next_c = it1_c-col.begin();
	// }
// 	
	// cout<<prev_r<<" "<<next_r<<" "<<prev_c<<" "<<next_c<<"\n";
	// ll mini = minii(abs(prev_r-r) , abs(r-next_r) , abs(c-prev_c) , abs(c-next_c))+1;
	// cout<<mini<<"\n";
	
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