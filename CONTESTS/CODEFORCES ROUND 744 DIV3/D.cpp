
// Problem: D. Productive Meeting
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll n;
	cin>>n;
	int ar[n];
//	vector<pair<int,int>>v;
	 priority_queue<pair<int,int>>pq;
	// priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>minh;
// 	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		// v.push({ar[i], i});
		 pq.push({ar[i], i});
		// minh.push({ar[i], i});
	}
	
	vector<pair<int,int>>v;
	while(!pq.empty() and !(pq.size()==1))
	{
		auto f = pq.top();
		int fval = f.first;
		int find = f.second;
		pq.pop();
		auto s = pq.top();
		pq.pop();
		int sval = s.first;
		int sind = s.second;
		
		if(sval!=0)
		{
			v.push_back({find, sind});
			pq.push({fval-1, find});
			pq.push({sval-1, sind});
		}
		else
		{
				pq.push({fval, find});
		}
	}
	
	cout<<v.size()<<"\n";
	//sort(v.begin(), v.end());
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first + 1<<" "<<v[i].second + 1<<"\n";
	}
	
}
int main()
{
	ll tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}