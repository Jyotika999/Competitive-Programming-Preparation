
// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool vis[1005][1005];

void dfs(int i, int j, vector<vector<char>>&grid, int n, int m)
{
	if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='#' || vis[i][j]==1)
	return;
	
	vis[i][j]=1;
	
	dfs(i-1, j, grid, n, m);
	dfs(i+1, j, grid, n, m);
	dfs(i, j-1, grid, n, m);
	dfs(i, j+1, grid, n, m);
	
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	memset(vis, 0, sizeof(vis));
	
	vector<vector<char>>grid(n, vector<char>(m));
	// char grid[n][m];
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}
	
	ll room=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			if(vis[i][j]==0 and grid[i][j]=='.')
			{
				dfs(i, j, grid, n, m);
				room++;
			}
		}
	}
	cout<<room<<"\n";
	
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