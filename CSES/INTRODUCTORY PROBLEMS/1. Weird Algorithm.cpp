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
	ll n;
	cin>>n;
	cout<<n<<" ";
	while(n!=1)
	{
		if(n%2==0)
		{
			n/=2;
		}
		else
		{
			n = n*3;
			n+=1;
		}
		cout<<n<<" ";
	}
	
	
}


int main()
{

   

	fastio;
	ll tc=1;
//	cin>>tc;
	while(tc--)
	{
	solve();
	}
} 