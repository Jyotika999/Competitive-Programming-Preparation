int getIdenticalTwinsCount(vector<int> &arr) {
    // add your logic here
	
	map<int,int>mp;
	int n = arr.size();
	int twins=0;
	
	for(int i=0;i<n;i++)
	{
		
		mp[arr[i]]++;
	}
	
	int ct=0;
	for(auto it : mp)
	{
		int cur=it.second;
		ct+=cur*(cur-1)/2;
	}
	
	return ct;
	
}