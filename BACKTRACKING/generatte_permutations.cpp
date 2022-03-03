// GENERATING PERMUTATIONS OF GIVEN ARRAY

#include<bits/stdc++.h>
using namespace std;

void permute(int ar[], int n, unordered_map<int,int>mp, vector<int>temp)
{
	if(temp.size()==n)
	{
		// base case you have got one permutation
		// print this permutation and go further
		
		for(int i=0;i<n;i++)
		{
			cout<<temp[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(mp[ar[i]]==0)
		{
			// include the current element
			temp.push_back(ar[i]);
			mp[ar[i]]=1;
			permute(ar, n, mp, temp);
			temp.pop_back();
			mp[ar[i]]=0;
		}
		else
		{
			// already this element is considered
			// dont count it
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	unordered_map<int,int>mp;
	vector<int>temp;
	permute(ar, n, mp, temp);
}