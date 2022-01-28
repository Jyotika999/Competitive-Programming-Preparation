
// Problem: A. Tokitsukaze and Enhancement
// Contest: Codeforces - Codeforces Round #573 (Div. 2)
// URL: https://codeforces.com/contest/1191/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
// Category AA if HP is in the form of (4n+1)(4n+1), that is, when divided by 44, the remainder is 11;
// Category BB if HP is in the form of (4n+3)(4n+3), that is, when divided by 44, the remainder is 33;
// Category CC if HP is in the form of (4n+2)(4n+2), that is, when divided by 44, the remainder is 22;
// Category DD if HP is in the form of 4n4n, that is, when divided by 44, the remainder is 00.
	
	ll rem = n%4;
	char ans_='*';
	ll ans=0;
	ll one = n+1;
	ll two = n+2;
	
	
	
	if(rem==0)
	{
		ans_='D';
		// convert D into A, B or C
		
		ll rem1 = one%4;
		ll rem2 = two%4;
		
		if(rem1==1 || rem2==1)
		{
			ans_='A';
			if(rem1==1)
			ans=1;
			else
			ans=2;
		}
		else if(rem1==3|| rem2==3)
		{
			ans_='B';
			if(rem1==3)
			ans=1;
			else
			ans=2;
		}
		else if(rem1==2 || rem2==2)
		{
			ans_='C';
			if(rem1==2)
			ans=1;
			else
			ans=2;
			
		}
	}
	else if(rem==1)
	{
		ans_= 'A';
		ans=0;
	}
	else if(rem==2)
	{
		ans_='C';
		// convert to B or A
		
		ll rem1= one%4;
		ll rem2= two%4;
		// cout<<rem1<<" "<<rem2<<"\n";
		if(rem1==1 || rem2==1)
		{
			ans_='A';
			if(rem1==1)
			{
				ans=1;
			}
			else
			{
				ans=2;
			}
		}
		else if(rem1==3 || rem2==3)
		{
			
			ans_='B';
			if(rem1==3)
			{
				ans=1;
			}
			else
			{
				ans=2;
			}
		
		}
		
	}
	else if(rem==3)
	{
		ans_='B';
		ll rem1 = one%4;
		ll rem2 = two%4;
		
		if(rem1==1 || rem2==1)
		{
			ans_='A';
			if(rem1==1)
			{
				ans=1;
			}
			else
			{
				ans=2;
			}
		}
	}
	
	

	cout<<ans<<" "<<ans_<<"\n";
	
}
int main()
{
	ll tc=1;
	// cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}