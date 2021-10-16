

// Problem: Staying Hydrated
// Contest: Google Coding Competitions - Round G 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3a1c
// Memory Limit: 1024 MB
// Time Limit: 40000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll v[100005][4];

void solve()
{
	ll k;
	cin>>k;
	
	//vector<vector<ll>>v(k, vector<ll>(4));
	//ll v[k][4];
	
	vector<ll>x;
	vector<ll>y;
	
	for(ll i=0;i<k;i++)
	{
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		//v[i]= {x1, y1, x2, y2};
		v[i][0]=x1;
		v[i][1]=y1;
		v[i][2]=x2;
		v[i][3]=y2;
		x.push_back(x1);
		x.push_back(x2);
		y.push_back(y1);
		y.push_back(y2);
		// x.push_back(x1);
		// x.push_back(x2);
		// y.push_back(y1);
		// y.push_back(y2);
	//	v[i]=({x1, y1, x2, y2}); 
	}

	ll sx=x.size();
	ll sy=y.size();
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());


ansx = x[k-1];
ansy = y[k-1];
	cout<<ansx<<" "<<ansy<<" ";
	
	//cout<<(ll)sx/x.size()<<" "<<sy/y.size()<<"\n";
	
	
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