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

void solve()
{
	
	ll n;
	cin>>n;
	
	ll xorr=0;
	
	for(ll i=1;i<=n;i++)xorr = xorr^i;
	
	for(ll i=1;i<=n-1;i++)
	{
		ll x;
		cin>>x;
		xorr = xorr^x;
	}
	
	cout<<xorr<<"\n";
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