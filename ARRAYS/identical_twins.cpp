int getIdenticalTwinsCount(vector<int> &arr) {
    // add your logic here
	int n = arr.size();
	int ans=0;
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
		
		//cout<<arr[i]<<" "<<mp[arr[i]]<<" "<<ans<<"\n";
	}
	
	for(auto it : mp)
	{
		int ff = it.first;
		int ss = it.second;
		
		ans+= (ss*(ss-1)/2);
	}
	return ans;
}