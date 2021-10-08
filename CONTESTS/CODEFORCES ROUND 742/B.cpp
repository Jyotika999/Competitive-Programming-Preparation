
// Problem: B. MEXor Mixup
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
int x[300005];

void solve()
{
	int m, b;
	cin>>m>>b;
	
	int ans=0;
	ans = m;
	
	int c = x[m-1];
	
	
	if(c==b)
	{
		cout<<ans<<"\n";
		return;
	}
	
	c= c^b;
	if(c==m)
	ans+=2;
	else
	ans+=1;
	
	cout<<ans<<"\n";
	
}
int main()
{
	int t;
	cin>>t;
	x[0]=0;
	for(int i=1;i<300005;i++)
	{
		x[i] = x[i-1]^i;
	}
	while(t--)
	{
		solve();
	}
}