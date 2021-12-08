
// Problem: Weird Algorithm
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1068
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	cout<<n<<" ";
	while(n!=1)
	{
		if(n%2==0)
		n/=2;
		else
		{
			n=n*3;
			n++;
		}
		cout<<n<<" ";
	}
	// cout<<n<<" ";
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