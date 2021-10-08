
// Problem: B. MIN-MEX Cut
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string s;
	cin>>s;
	
	int ans=0;
	int zeroes = count(s.begin(), s.end(), '0');
	
	// sare zero, ans = 0
	if(zeroes==0)
	{
		ans = 0;
	}
	// sare one, ans = 1
	else if(zeroes==s.length())
	{
		ans = 1;
	}
	else
	{ 
	// mixture of 0 and 1 , toh 0 wale segment ko alag rkhke compute kro 
		int temp=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='0')
			{
				temp=1;
			}
			else
			{
				ans+= temp;
				temp=0;
			}
		}
		ans+=temp;
	}
	
	cout<<min(ans, 2)<<"\n";
}
int main()
{
	ll tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}