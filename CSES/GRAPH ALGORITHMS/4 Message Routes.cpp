// YOU WILL NEVER REGRET WORKING HARD 


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 100000
#define ms(a,x) memset(a,x,sizeof(a))
#define pq priority_queue<ll> 
#define bit __builtin_popcount
#define pb push_back
#define pob pop_back()
#define vll vector<ll>
const int N=10000001;
vector<ll>g[1000001];
ll vis[1000001];
ll dis[1000001];
ll parent[1000001];
void bfs(ll node)
{
	vis[node]=1;
	parent[node]=node;
	dis[node]=1;
	
	queue<ll>q;
	q.push(node);
	
	while(!q.empty())
	{
		ll cur = q.front();
		q.pop();
		//cout<<cur<<"\n";
		
		for(auto child : g[cur])
		{
			if(!vis[child])
			{
				q.push(child);
				vis[child]=1;
				dis[child]= dis[cur]+1;
				parent[child] = cur;
			}
		}
	}
	
	
	
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	ms(vis, 0);
	ms(parent, -1);
	ms(dis, 0);
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	bfs(1);
	
	/*for(ll i=1;i<=n;i++)
	{
		cout<<i<<" "<<parent[i]<<"\n";
	}*/
	
	if(!vis[n])
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		cout<<dis[n]<<"\n";
		
		vector<ll>path;
		for(ll i=n;i!=1;i=parent[i])
		{
			path.pb(i);
		}
		path.pb(1);
		reverse(path.begin(), path.end());
		
		for(auto i : path)
		{
			cout<<i<<" ";
		}
	}
	
}


int main()
{

   

	fastio;
	ll tc=1;
	//cin>>tc;
	while(tc--)
	{
	solve();
	}
} 