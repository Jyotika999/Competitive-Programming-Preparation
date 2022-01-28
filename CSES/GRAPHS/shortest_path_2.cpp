// Problem: Shortest Routes II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1672
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INT_MAX 1e18
void solve()
{
	ll n,m,q;
	cin>>n>>m>>q;
	// cout<<n<<" "<<m<<" "<<q<<"\n";
	
	ll dis[n+5][n+5];
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		 dis[i][j]= 1e18;
		
		// cout<<"\n";
	}
	
	// memset(dis, INT_MAX, sizeof(dis));
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		// cout<<u<<" "<<v<<" "<<wt<<"\n";
		dis[u][v]= min(wt, dis[u][v]);
		dis[v][u]= min(wt, dis[v][u]);
	}
	
	for(ll i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
// /	
	for(ll i=1;i<=n;i++)
	{
		for(ll u=1;u<=n;u++)
		{
			for(ll v=1;v<=n;v++)
			{
				if(dis[u][i]<INT_MAX and dis[i][v]<INT_MAX)
				dis[u][v] = min(dis[u][v] , dis[u][i]+ dis[i][v]);
			}
		}
	}
	
	// for(ll i=1;i<=n;i++)
	// {
		// for(ll j=1;j<=n;j++)
		// cout<<dis[i][j]<<" ";
// 		
		// cout<<"\n";
	// }
	
		
	// // ll q;
	// // cin>>q;
	while(q--)
	{
		ll u,v;
		cin>>u>>v;
		// cout<<u<<" "<<v<<"\n";
		if(dis[u][v]!=INT_MAX)
		cout<<dis[u][v]<<"\n";
		else
		cout<<"-1\n";
	}
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