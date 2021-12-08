#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	if(n>=42)
	n++;
	cout<<"AGC"<<setfill('0')<<setw(3)<<n<<"\n";
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