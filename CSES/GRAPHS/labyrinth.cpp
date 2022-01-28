
// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool vis[1005][1005];
char parent[1005][1005];

void solve()
{
	ll n,m;
	cin>>n>>m;
	char grid[n][m];
	ll startx = -1;
	ll starty = -1;
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='A')
			{
				startx = i;
				starty = j;
			}
		}
	}
	
	queue<pair<ll,ll>>q;
	q.push({startx, starty});
	vis[startx][starty]=1;
	parent[startx][starty]='A';
	ll found=0;
	ll x,y;
	
	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();
		 x = cur.first;
		 y = cur.second;
		
		if(grid[x][y]=='B')
		{
			found=1;
			break;
		}
		
		// left
		// y-1, x
		if(y-1>=0 and vis[x][y-1]==0 and grid[x][y-1]!='#')
		{
			vis[x][y-1]=1;
			q.push({x, y-1});
			parent[x][y-1]='L';
		}
		
		// down
		// y, x+1
		if(x+1<n and vis[x+1][y]==0 and grid[x+1][y]!='#')
		{
			vis[x+1][y]=1;
			q.push({x+1, y});
			parent[x+1][y]='D';
		}
		
		// up
		// y, x-1
		if(x-1>=0 and vis[x-1][y]==0 and grid[x-1][y]!='#')
		{
			vis[x-1][y]=1;
			q.push({x-1, y});
			parent[x-1][y]='U';
		}
		
		// right
		// y+1, x
		if(y+1<m and vis[x][y+1]==0 and grid[x][y+1]!='#')
		{
			vis[x][y+1]=1;
			q.push({x, y+1});
			parent[x][y+1]='R';
		}
		
		
	}
	
	if(found)
	cout<<"YES\n";
	else
	{
		cout<<"NO\n";
		return;}
	
	
	string path="";
// 	
	while(parent[x][y]!='A')
	{
		// cout<<x<<" "<<y<<" "<<parent[x][y]<<"\n";
		path.push_back(parent[x][y]);
		if(parent[x][y]=='L')
		{
			y++;
		}
		else if(parent[x][y]=='R')
		{
			y--;
		}
		else if(parent[x][y]=='U')
		{
			x++;
		}
		else if(parent[x][y]=='D')
		{
			x--;
		}
	}
// 	
	cout<<path.length()<<"\n";
	reverse(path.begin(), path.end());
	cout<<path<<"\n";
// 	
	
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