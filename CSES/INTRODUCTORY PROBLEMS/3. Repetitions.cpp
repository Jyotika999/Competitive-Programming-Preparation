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


void solve()
{
	string s;
	cin>>s;
	
	ll n = s.length();
	ll maxi = 1;
	ll ct=1;
	
	for(ll i=1;i<n;i++)
	{
		if(s[i]== s[i-1])ct++;
		else ct=1;
		maxi = max(maxi, ct);
		
	}
	cout<<maxi<<"\n";
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