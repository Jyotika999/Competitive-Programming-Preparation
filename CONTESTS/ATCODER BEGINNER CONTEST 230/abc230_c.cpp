
// Problem: C - X drawing
// Contest: AtCoder - AtCoder Beginner Contest 230
// URL: https://atcoder.jp/contests/abc230/tasks/abc230_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool black(ll i, ll j, ll n, ll a, ll b)
{
	//max(1−A,1−B)≤k≤min(N−A,N−B), paint (A+k, B+k)
	//max(1−A,B−N)≤k≤min(N−A,B−1), paint (A+k,B−k)
	ll f1 = max(1-a, 1-b);
	ll f2 = min(n-a, n-b);
	 
	ll s1 = max(1-a, b-n);
	ll s2 = min(n-a, b-1);
	
	// first scenario
	// i=A+k, j=B+k
	// 2k=i+j-a-b
	if(i-j==a-b)
	{
		ll dif = i+j-a-b;
		if(dif%2!=0)
		return false;
		
		dif/=2;
		if(dif>=f1 and dif<=f2)
		return true;
	}
	
	// second scenario
	// i=A+k, j=B-k
	// i-j-a+b=2k
	if(i+j==a+b)
	{
		ll dif = i-j-a+b;
		if(dif%2!=0)
		return false;
		dif/=2;
		if(dif>=s1 and dif<=s2)
		return true;
		
		
	}
	
	return false;
}


void solve()
{
	ll n,a,b;
	cin>>n>>a>>b;
	ll p,q,r,s;
	cin>>p>>q>>r>>s;
	
	for(ll i=p;i<=q;i++)
	{
		for(ll j=r;j<=s;j++)
		{
			if(black(i, j, n, a, b))
			{
				cout<<"#";
			}
			else
			{
				cout<<".";
			}
		}
		cout<<"\n";
	}
}
int main()
{
	ll tc=1;
	// cin>>tc;
	while(tc--)
	{
		solve();
	}
}