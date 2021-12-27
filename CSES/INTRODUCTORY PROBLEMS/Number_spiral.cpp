
// Problem: Number Spiral
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1071
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll x,y;
	cin>>x>>y;
	
	// totally observation based question
	// pattern of sqaures of numbers
	// 1 , 4, 9, 16, 25, 36,.....
	ll ans=0;
	if(x<y)
	{
		if(y%2!=0)
		{
			ans=(y*y)-x+1;
		}
		else
		{
			ans=(y-1)*(y-1)+x;
		}
	}
	else
	{
		if(x%2==0)
		{
			ans=(x*x)-y+1;
		}
		else
		{
			ans=(x-1)*(x-1)+y;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ll tc=1;
	 cin>>tc;
	while(tc--)
	{
		solve();
	}
}