
// Problem: B - Triple Metre
// Contest: AtCoder - AtCoder Beginner Contest 230
// URL: https://atcoder.jp/contests/abc230/tasks/abc230_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string s1;
	cin>>s1;
	ll n = s1.length();
	char f;
	char s;
	char t;
	if(s1[0]=='o')
	{
		f='o';
		s='x';
		t='x';
	}
	else
	{
		f='x';
		s='x';
		t='o';
		
		if(n>=2 and s1[1]=='x')
		{
			f='x';
			s='x';
			t='o';
		}
		else if(n>=2 and s1[1]=='o')
		{
			f='x';
			s='o';
			t='x';
		}
	}
	// xxo
	int fl=1;
	//cout<<f<<" "<<s<<" "<<t<<"\n";
	
	for(int i=0;i<n;i++)
	{
		if((i)%3==0)
		{
			if(s1[i]==f)continue;
			else fl=0;
		}
		else if((i)%3==1)
		{
			if(s1[i]==s)continue;
			else fl=0;
		}
		else
		{
			if(s1[i]==t)continue;
			else fl=0;
		}
	}
	
	if(fl)
	cout<<"Yes\n";
	else
	cout<<"No\n";
}
int main()
{
	ll tc=1;
	//cin>>tc;
	while(tc--)
	{
		solve();
	}
}