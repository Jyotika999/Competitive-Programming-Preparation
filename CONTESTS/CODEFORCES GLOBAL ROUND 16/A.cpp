
// Problem: A. Median Maximization
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	int n, s;
	cin>>n>>s;
	//cout<<n<<" "<<s<<"\n";
	int x = (n/2)+1;
	int ans = s/x;
	cout<<ans<<"\n";
}
int main()
{
	ll tc;
	cin>>tc;
	while(tc--)
	{
		//cout<<tc<<"\n";
		solve();
	}
}