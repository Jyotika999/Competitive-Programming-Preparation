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

char ar[1001][1001];
ll vis[1001][1001];
ll dis[1001][1001];
ll parent[1001][1001];

string path="";
ll n,m;
ll row[4];
ll col[4];


bool valid(ll x, ll y)
{
	if(x>=0 && x<n && y>=0 && y<m && ar[x][y]!='#')return true;
	else return false;
}

char direction(ll num)
{
	if(num==0)return 'U';
	if(num==1)return 'R';
	if(num==2)return 'L';
	if(num==3)return 'D';
	
}
void bfs(ll x, ll y, ll bx, ll by)
{
	ll dx[4] = {-1, 0, 0, 1};
	ll dy[4] = {0, 1, -1, 0};
	
	queue<pair<ll,ll>>q;
	q.push({x,y});
	
	vis[x][y]=1;
	dis[x][y]=0;
	
	
	ll curx=-1, cury=-1;
	
	//string ans="";
	while(!q.empty())
	{
		curx = q.front().first;
		cury = q.front().second;
		//cout<<curx<<" "<<cury<<"\n";
		q.pop();
		
		if(ar[curx][cury]=='B')break;
		
		for(ll i=0;i<4;i++)
		{
			ll newx = curx + dx[i];
			ll newy = cury + dy[i];
			
			if(valid(newx, newy) && (vis[newx][newy]==0))
			{
			q.push({newx, newy});
			vis[newx][newy]=1;
			dis[newx][newy] = dis[curx][cury]+1;
			//char ch = direction(i);
			parent[newx][newy] = i;
			//cout<<newx<<" "<<newy<<" "<<direction(i)<<"\n";
			}
		}
	}

	vector<char>path;
	if(!vis[bx][by])
	{
		cout<<"NO\n";
	}
	else
	{
		ll level = dis[bx][by];
		while(bx!=x or by!=y)
		{
			ll d = parent[bx][by];
			
			path.pb(direction(d));
			bx = bx- dx[d];
			by = by- dy[d];
		}
		reverse(path.begin(), path.end());
		cout<<"YES\n"<<level<<"\n";
		
		for(ll i=0;i<(ll)path.size();i++)cout<<path[i];
	}

	
}
void solve()
{
	//ll n,m;
	cin>>n>>m;
	
	ll ax=0, ay=0, bx=0, by=0; 
	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(ll j=0;j<m;j++)
		{
			ar[i][j] = s[j];
			if(ar[i][j]=='A'){ ax=i, ay=j;}
			if(ar[i][j]=='B'){ bx=i, by=j;}
		}
	}
	
	
	/*cout<<ax<<" "<<ay<<"\n";
	cout<<bx<<" "<<by<<"\n";
	*/
	
	bfs(ax, ay, bx, by);
	
	
	
}


int main()
{

   

	fastio;
	memset(vis, 0, sizeof(vis));
	
	solve();
	
} 