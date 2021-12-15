int longestConsecutiveSequence(vector<int> &A) {
    // add your logic here
	map<int,int>mp;
	int n =A.size();
	int maxlen=1;
	
	for(int i=0;i<n;i++)
	{
		mp[A[i]]=1;
	}
	
	int ct=1;
	for(auto it : mp)
	{
		int ff = it.first;
		int ss = it.second;
		
		if(mp[ff-1]!=0)
		{
			ct++;
			maxlen= max(maxlen, ct);
		}
		else
		{
			ct=1;
		}
	}
	
	return maxlen;
}