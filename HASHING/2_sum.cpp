pair<int,int> twoSum(vector<int> &A, int target) {
    // add your logic here
	
	pair<int,int>p;
	map<int,int>mp;
	
	int n = A.size();
	for(int i=0;i<n;i++)
	{
		if(mp[target-A[i]]!=0)
		{
			p.first=mp[target-A[i]]-1;
			p.second=i;
			break;
		}
		else
		{
			mp[A[i]]=i+1;
		}
	}
	
	return p;
	
}