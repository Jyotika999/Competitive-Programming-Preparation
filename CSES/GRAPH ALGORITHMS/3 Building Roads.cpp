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
ll parent[1000001];
ll sz[1000001];

ll find(ll node)
{
	if(node == parent[node])return node;
	else return parent[node] = find(parent[node]);
}
void Union(ll a, ll b)
{
	 a = find(a);
	 b = find(b);
	if(a != b)
	{
		if(sz[a]<sz[b])
		swap(a,b);
		
		parent[b]= a;
		sz[a]+=sz[b];
	}
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	
	memset(sz, 0, sizeof(sz));
	for(ll i=0;i<1000001;i++)
	{
		parent[i]=i;
	}
	
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		Union(u,v);
	}	
	
	//cout<<n-1-m<<"\n";
   
	vector<ll>v;
	for(ll i=1;i<=n;i++)
	{
		if(i== parent[i])v.pb(i);
	}
	
	cout<<v.size()-1<<"\n";
	for(ll i=1;i<(ll)v.size();i++)
	{
		cout<<v[0]<<" "<<v[i]<<"\n";
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