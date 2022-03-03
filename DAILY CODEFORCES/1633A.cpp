// Problem: A. Div. 7
// Contest: Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1633/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	string n;
	cin>>n;
	
	ll num = stoi(n);
	if(num%7==0)
	{
		cout<<num<<"\n";
	}
	else{
		// ll last= num%10;
		string s = n.substr(0, n.length()-1);
		
		for(ll i=0;i<9;i++)
		{
			string str = s+to_string(i);
			ll org = stoi(str);
			if(org%7==0)
			{
				cout<<org<<"\n";
				break;
			}
		}
	}
	
}
int main()
{
	ll tc=1;
	cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}