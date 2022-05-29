// next smaller to  right

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	int ar[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	vector<int>ans(n,0);
	stack<int>s;
	
	for(int i=n-1;i>=0;i--)
	{
		if(s.empty())
		ans[i]=-1;
		
		
		else
		{
			while(!s.empty() and (s.top()>ar[i]))
			s.pop();
			
			
			// cout<<ar[i]<<" "<<s.top()<<"\n";
			if(s.empty())
			ans[i]=-1;
			else
			ans[i]=s.top();
			
			
		}
		s.push(ar[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	
}