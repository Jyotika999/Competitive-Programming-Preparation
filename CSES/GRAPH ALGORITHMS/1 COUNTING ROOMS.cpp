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
ll vis[1001][1001];
char ar[1001][1001];
ll n,m;
ll expo(ll a, ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res*=a;
		res*=a;
		b=b<<1;
	}
	return res;
}
bool valid(ll x, ll y)
{
	if(x>=0 && x<n && y>=0 && y<m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void dfs(ll x, ll y)
{
	if(!valid(x,y))return;
	if(ar[x][y]=='#')return;
	if(vis[x][y])return;
	vis[x][y]=1;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
	
}

void solve()
{
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(ll j=0;j<m;j++)
		{
			ar[i][j]=s[j];
		}
	}
	
	
	
	ll ct=0;
	memset(vis, 0, sizeof(vis));
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			if(!(vis[i][j]) && ar[i][j]=='.')
			{
				dfs(i,j);
				ct++;
			}
		}
	}
	
	cout<<ct<<"\n";
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