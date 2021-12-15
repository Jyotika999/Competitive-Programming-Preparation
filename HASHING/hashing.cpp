#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int> &A, int target) {
    // add your logic here
	 vector<vector<int>>ans;
      map<tuple<int,int,int,int>,int>mp;
	
	sort(A.begin(), A.end());
	int n =A.size();
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int left=j+1;
			int right=n-1;
			int x = target-A[i]-A[j];
			
			while(left<right)
			{
				if(A[left]+A[right]==x)
				{
                    	vector<int>temp;
						temp.push_back(A[i]);
						temp.push_back(A[j]);
						temp.push_back(A[left]);
						temp.push_back(A[right]);
					if(mp[{A[i], A[j], A[left], A[right]}]==0)
					{
					
						ans.push_back(temp);
						mp[{A[i], A[j], A[left], A[right]}]++;
					}
					left++;
					right--;
				}
				else if(A[left]+A[right]<x)
				{
					left++;
				}
				else{
					right--;
				}
			}
		}
	}
	
	
	return ans;
        
}