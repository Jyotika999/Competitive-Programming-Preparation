// YOU WILL NEVER REGRET WORKING HARD 

// round trip problem
// cycle path retrieval
// revision of cycle detection and finding the number of connected components

// cycle detection using back edge detection , which referes to visiting such a neighbouring node of the current node , if already visited 
// and is not the parent node, it will mean that there is a back edge which detectd cycle detection

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
vector<int>g[1000001];
bool vis[1000001];
ll parent[1000001];
ll starting=0, ending=0;
ll flag=0;
void dfs(ll node, ll p)
{
	vis[node]=1;
	parent[node]=p;
	
	for(auto child : g[node])
	{
		if(vis[child] && child!=p)
		{
			starting= node;
			ending = child;
			//return;
			flag=1;
		}
		if(!vis[child])
		{
			dfs(child, node);
		}
		
	}
}


void solve()
{
	ll n,m;
	cin>>n>>m;
	
	ms(vis, false);
	ms(parent, -1);
	
	for(int i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,-1);
		}
	}
	
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cout<<"IMPOSSIBLE\n";return;
		}
	//	cout<<i<<" "<<parent[i]<<"\n";
	}
	
//	cout<<starting<<" "<<ending<<"\n";
	if(flag==0){
	
			cout<<"IMPOSSIBLE\n";return;	
	}
	vector<int>ans;
	ans.pb(ending);
	int temp = ending;
	
	while(temp!=starting)
	{
		ans.pb(parent[temp]);
		temp = parent[temp];
	}
	ans.pb(ending);
	cout<<ans.size()<<"\n";
	for(auto i : ans)
	{
		cout<<i<<" ";
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