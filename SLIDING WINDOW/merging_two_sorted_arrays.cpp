vector<int> mergeSortedArrays(vector<int> &A, vector<int> B) {
    // add your logic here
	int na = A.size();
	int nb = B.size();
	vector<int>sorted_Array(na+nb);
	
	
	
	int a=0;
	int b=0;
	int k=0;
	
	while(a<na and b<nb)
	{
		if(A[a]<B[b])
		{
			sorted_Array[k++]=A[a++];
		}
		else
		{
			sorted_Array[k++]=B[b++];
		}
	}
	while(a<na)
	{
		sorted_Array[k++]=A[a++];
	}
	while(b<nb)
	{
		sorted_Array[k++]=B[b++];
	}
	return sorted_Array;
	
}