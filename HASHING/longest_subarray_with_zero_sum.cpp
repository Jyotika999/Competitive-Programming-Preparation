int longestSubarrayWithZeroSum(vector<int> &A) {
    // add your logic here
	
	
	int n = A.size();
	int maxlen=0;
	map<int,int>mp;
	
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=A[i];
		if(mp[sum]!=0 || sum==0)
		{
			maxlen= max(maxlen, i-mp[sum]+1);
		}
		if(mp[sum]==0)
		mp[sum]=i+1;
		
		//cout<<sum<<" "<<mp[sum]<<"\n";
	}
	
	return maxlen;
	
}
