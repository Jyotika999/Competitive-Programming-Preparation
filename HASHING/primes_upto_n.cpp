vector<int> primesUptoN(int n) {
    
    bool prime[n+1];
	memset(prime, true, sizeof(prime));
	
	vector<int>ans;
	for(int i=2;i*i<=n;i++)
	{
		if(prime[i]==true){
		for(int j=2*i;j<=n;j+=i)
		{
			prime[j]=0;
		}
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		if(prime[i])
			ans.push_back(i);
	}
	
	return ans;
}