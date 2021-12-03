
// Problem: A - AtCoder Quiz 3
// Contest: AtCoder - AtCoder Beginner Contest 230
// URL: https://atcoder.jp/contests/abc230/tasks/abc230_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string zero(int n, int val)
{
	if(n==1)
	return "00";
	else if(n==2)
	return "0";
	else
	return "";
	// if(val%100==0)
	// {
		// return "0";
	// }
	// else
	// {
// 		
	// }
}
void solve()
{
	ll val;
	cin>>val;
	string s="AGC";
	string ch="";
	
	int n=0;
	int temp=val;
	while(temp)
	{
		temp/=10;
		n++;
	}
//	cout<<n<<"\n";
	if(val<42)
	ch= zero(n, val)+to_string(val);
	else
	ch= zero(n, val)+to_string(val+1);
	cout<<s+ch<<"\n";
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