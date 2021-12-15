
// Problem: Tower of Hanoi
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2165
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// logic behind tower of hanoi problem
// let us say that we have three stacks which are A,B, C
// move (n-1)disks from A to B
// move last disk from A to C
// move (n-1)disks from B to C

// base case if n==1
// three rods, from , to and helper
// depending upon the above pattern


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<int,int>>v;

void tower_of_hanoi(ll n, ll from, ll to, ll helper)
{
	if(n==1)
	{
		v.push_back({from, to});
		return;
	}
	
	// moving n-1 disks from A to B
	tower_of_hanoi(n-1, from, helper, to);
	
	// moving last disk from A to C
	v.push_back({from, to});
	
	// moving n-1 disks from B to C
	tower_of_hanoi(n-1, helper, to, from);
	
	
	
}

void solve()
{
	ll n;
	cin>>n;
	tower_of_hanoi(n, 1, 3, 2);
	cout<<v.size()<<"\n";
	for(auto it : v)
	{
		cout<<it.first<<" "<<it.second<<"\n";
	}
}
int main()
{
	ll tc=1;
	 // cin>>tc;
	while(tc--)
	{
		solve();
	}
}