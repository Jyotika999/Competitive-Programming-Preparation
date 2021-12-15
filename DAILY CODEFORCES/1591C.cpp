
// Problem: C. Minimize Distance
// Contest: Codeforces - Codeforces Round #759 (Div. 2, based on Technocup 2022 Elimination Round 3)
// URL: https://codeforces.com/contest/1591/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll depot_k_bags(vector<ll>v, ll k)
{
	if(v.size()==0)
	return 0;
	
	ll n=v.size();
	priority_queue<ll>pq;
	
	for(ll i=0;i<n;i++)
	{
		pq.push(v[i]);
	}
	ll ans=0;
	
	while(!pq.empty())
	{
		if(ans==0)
		ans+=pq.top();
		else
		ans+=2*pq.top();
		ll ct=k;
		while(ct and !pq.empty())
		{
			
			ct--;
			pq.pop();
		}
		
	}
	// cout<<ans<<"\n";
	return ans;
}
void solve()
{
	ll n, k;
	cin>>n>>k;
	ll ar[n];
	vector<ll>pos;
	vector<ll>neg;
	ll max_pos=0;
	ll max_neg=0;
	
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
		if(ar[i]>0)
		{
			pos.push_back(ar[i]);
			max_pos = max(max_pos, ar[i]);
		}
		else
		{
			neg.push_back(abs(ar[i]));
			max_neg = max(max_neg, abs(ar[i]));
		}
	}
	
	ll pos_ans= depot_k_bags(pos, k);
	ll neg_ans= depot_k_bags(neg, k);
	// cout<<pos_ans<<" "<<neg_ans<<" ";
	cout<<pos_ans+neg_ans+min(max_pos, max_neg)<<"\n";
	
	
	
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