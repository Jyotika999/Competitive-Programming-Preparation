vector<int> kSubarraySum(vector<int> &A, int k) {
	// add your logic here
	
	int n = A.size();
	vector<int>ans;
	int i=0;
	int sum=0;
	int j=0;
	

	
	for(int j=0;j<n;j++)
	{
		sum+=A[j];
		
		while(j-i+1>k)
		{
			sum-=A[i];
			i++;
		}
		if(j-i+1==k)
		{
			ans.push_back(sum);
		}
		
		
		
		
	}
	return ans;
	
	
	
	
	
}