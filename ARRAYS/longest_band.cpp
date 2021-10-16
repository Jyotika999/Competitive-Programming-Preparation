// longest band

// given an array containing n integers , find the length of the longest band

// a band is defined as a subsequence which can be reordered in such a manner that all elements appear consecutive



#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	int ar[n];
	map<int,int>freq;
	map<int,int>dp;
	
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		dp[ar[i]]=1;
		freq[ar[i]]++;
	}
	
	int maxi=0;
	sort(ar, ar+n);
	for(int i=0;i<n;i++)
	{
		if(freq[ar[i]-1])
		{
			dp[ar[i]] = dp[ar[i]-1]+1;
			maxi = max(maxi, dp[ar[i]]);
		}
	}
	
	cout<<maxi<<"\n";
}