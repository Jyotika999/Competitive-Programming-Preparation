
// Problem: RGB Construction
// Contest: CodeChef - December Cook-Off 2021 Division 2
// URL: https://www.codechef.com/COOK136B/problems/RGBCONST
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll r,g,b;
	cin>>r>>g>>b;
	
	
	
	string s="";
	
	vector<pair<ll,ll>>v;
	
	if(r+g<b)
	{
		cout<<"-1\n";
	}
	else
	{
		// pehle R-G
		// Fir first R k sath attachable G
		// Fir first G k sath attachable R
		// Fir B sabke sath
		
		// since there must be atleast one r and one g between two b
		
		
		v.push_back({1,2});
		s+="RG";
		r--;
		g--;
		
		// R = node 1
		// G = node 2
		
		// ab first R ke sath sare possible G aajayenge
		int ct=3;
		while(r--)
		{
			s+="R";
			v.push_back({2,ct++});
		}
		
		// ab first G ke sath sare possible R aajaanynge
		while(g--)
		{
			s+="G";
			v.push_back({1, ct++});
		}
		// fir hum sare R aur G k sath B attach krdenge ,
		
		ll prev=1;
		// ll now_blue=1; 
		while(b--)
		{
			s+="B";
			v.push_back({prev++, ct++});
		}
		// so that the nodes between every two blue nodes,
		// contain atleast one G and one R 
		
		cout<<s<<"\n";
		for(auto it : v)
		{
			cout<<it.first<<" "<<it.second<<"\n";
		}
		
		
	}
	
	
	
	
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