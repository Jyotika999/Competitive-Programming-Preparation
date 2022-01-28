
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n,m, rx, ry, dx, dy;
	cin>>n>>m>>rx>>ry>>dx>>dy;
	
	ll xx=1;
	ll yy=1;
	ll ct=10;
	ll time=0;
	
	while(1)
	{
		// if(rx==n)
		// {
			// xx=-xx;
		// }
		// if(ry==m)
		// {
			// yy=-yy;
		// }
		if(rx==dx or ry==dy)
		break;
		
		
		time++;
		
			if(rx+xx>n || rx+xx<1)
			xx=-1*(xx);
			if(ry+yy>m || ry+yy<1)
			yy=-1*(yy);
		
		
			rx = rx+xx;
			ry = ry+yy;
		
		// cout<<rx<<" "<<ry<<"\n";
		
		
		// ct++;
	}
	
	cout<<time<<"\n";
	
	
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