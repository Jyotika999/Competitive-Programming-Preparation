
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll l1, l2, l3;
	cin>>l1>>l2>>l3;
	
	
	// breaking one stick to len of other two , which can form opposite sides of rectangle
	if(l1==l2+l3 || l2==l1+l3 || l3==l1+l2)
	{
		cout<<"YES\n";
		return;
	}
	else if(l1==l2 || l2==l3 || l3==l1)
	{
		// if any teo are equal 
		// then split the third , 
		// if even then possible else not
		
		if(l1==l2)
		{
			if(!(l3&1))
			{
				cout<<"YES\n";
				return ;
			}
		}
		else if(l3==l2)
		{
			if(!(l1&1))
			{
				cout<<"YES\n";
				return;
			}
		}
		else if(l1==l3)
		{
			if(!(l2&1))
			{
				cout<<"YES\n";
				return;
			}
		}
		else
		{
			cout<<"NO\n";
			return;
		}
		
	}
	
	{
		cout<<"NO\n";
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