// Problem: Monsters
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1194
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dx[4]={1, -1, 0, 0};
ll dy[4]={0,  0, 1, -1};
void solve()
{
	ll n,m;
	cin>>n>>m;
	
	char grid[n][m];
	ll cost[n][m];
	ll cost2[n][m];
	bool vis[n][m];
	bool vis2[n][m];
	
	memset(vis, 0, sizeof(vis));
	memset(vis2, 0, sizeof(vis2));
	memset(cost, 0, sizeof(cost));
	memset(cost2, 0, sizeof(cost2));
	
	ll startx =0;
	ll starty =0;
	
	queue<pair<ll,ll>>q;
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='A')
			{
				startx = i;
				starty = j;
				grid[i][j]='.';
			}
			else if(grid[i][j]=='M')
			{
				// cout<<i<<" "<<j<<"\n";
				q.push({i, j});
				grid[i][j]='.';
			}
		}
	}
	
	ll t=1;
	
	while(!q.empty())
	{
		auto cur = q.front();
		ll curx = cur.first;
		ll cury = cur.second;
		q.pop();
		
		vis[curx][cury]=1;
		
		for(ll k=0;k<4;k++)
		{
			ll xx = curx + dx[k];
			ll yy = cury + dy[k];
			
			if(xx>=0 and yy>=0 and xx<n and yy<m and grid[xx][yy]=='.' and vis[xx][yy]==0)
			{
				cost[xx][yy] =  (ll)t;
				vis[xx][yy]=1;
				q.push({xx, yy});
			}
		}
		t++;
	}
	
	
	queue<pair<ll,ll>>source;
	source.push({startx, starty});
	 t=1;
	char parent[n][m];
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			parent[i][j]='*';
		}
	}
	
	parent[startx][starty]='A';
	
	while(!source.empty())
	{
		auto cur = source.front();
		ll curx = cur.first;
		ll cury = cur.second;
		source.pop();
		
		// if(curx==n-1 || cury==m-1)
		// {
			// if(grid[curx][cury]=='.')
			// break;
		// }
		
		vis2[curx][cury]=1;
		
		for(ll k=0;k<4;k++)
		{
			ll xx = curx + dx[k];
			ll yy = cury + dy[k];
			
			if(xx>=0 and yy>=0 and xx<n and yy<m and grid[xx][yy]=='.' and vis2[xx][yy]==0)
			{
				cost2[xx][yy] =  t;
				vis2[xx][yy]=1;
				source.push({xx, yy});
				
				if(dx[k]==-1 and dy[k]==0)
				{
					parent[xx][yy] = 'U';
				}
				if(dx[k]==1 and dy[k]==0)
				{
					parent[xx][yy] = 'D';	
				}
				if(dx[k]==0 and dy[k]==-1)
				{
					parent[xx][yy] = 'L';
				}
				if(dx[k]==0 and dy[k]==1)
				{
					parent[xx][yy] = 'R';
				}
			}
			
			
			
		}
		t++;
	}
	
	ll des_x =0;
	ll des_y =0;
	ll flag=0;
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			// cout<<cost[i][j]<<" ";
			if(i==0 || i==n-1 || j==0 || j==m-1)
			{
				if(cost[i][j] > cost2[i][j])
				{
					des_x = i;
					des_y = j;
					flag=1;
					break;
				}
			}
		}
		// cout<<"\n";
	}
	
	// for(ll i=0;i<n;i++)
	// {
		// for(ll j=0;j<m;j++)
		// {
			// cout<<parent[i][j]<<" ";
		// }
		// cout<<"\n";
	// }
	
	if(flag==0)
	{
		cout<<"NO\n";
		return;
	}
	string path="";
	
	while(parent[des_x][des_y]!='A')
	{
		path+=parent[des_x][des_y];
		// cout<<des_x<<" "<<des_y<<"\n";
		if(parent[des_x][des_y]=='U')
		{
			des_x++;
		}
		else if(parent[des_x][des_y]=='D')
		{
			des_x--;
		}
		else if(parent[des_x][des_y]=='L')
		{
			des_y++;
		}
		else if(parent[des_x][des_y]=='R')
		{
			des_y--;
		}
	}
	
	

				
	reverse(path.begin(), path.end());
	
	cout<<"YES\n";
	cout<<path.length()<<"\n";
	cout<<path<<"\n";
	
	
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