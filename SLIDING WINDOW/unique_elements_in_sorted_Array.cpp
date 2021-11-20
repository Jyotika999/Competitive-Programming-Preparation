int removeDuplicates(vector<int> &A) {
    // add logic here
	int n = A.size();
	
	int ct=0;
	for(int i=0;i<n-1;i++)
	{
		if(A[i]==A[i+1])
			continue;
		else
		{ct++;}
	}
	return ct+1;
}