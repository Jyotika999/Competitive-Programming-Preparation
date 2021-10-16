
// Problem: Dogs and Cats
// Contest: Google Coding Competitions - Round G 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3771
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n , d, c, m;
	cin>>n>>d>>c>>m;
	string s;
	cin>>s;
	
	
	ll dog=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='D')
		dog++;
	}
	
	//cout<<dog<<" ";
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='C')
		{
			if(c>0)
			c--;
			else
			break;
		}
		if(s[i]=='D')
		{
			if(d>0)
			{
				d--;
				c+=m;
				dog--;
			}
			else
			{
				break;
			}
		}
	}
	
//	cout<<dog<<"\n";
	if(dog==0)
	cout<<"YES";
	else
	cout<<"NO";
	
	
}
int main()
{
	ll tc;
	cin>>tc;
	
	for(int i=1;i<=tc;i++)
	{
		//Case #3: NO
		cout<<"Case #"<<i<<": ";
		solve();
		cout<<"\n";
	}
}