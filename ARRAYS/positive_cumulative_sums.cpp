vector<int> getPositiveCumulativeSum(vector<int> &arr) {
	// add your logic here
	int n =  arr.size();
	vector<int>positive;
	
	if(arr[0]>0)
	{
		positive.push_back(arr[0]);
	}
	for(int i=1;i<n;i++)
	{
		arr[i]+=arr[i-1];
		if(arr[i]>0)
		{
			positive.push_back(arr[i]);
		}
	}
	return positive;
	
}