// Given a sorted array, check if there exist two numbers whose sum is zero.
// 
// Example
// A: [-3, 1, 3, 4]
// Answer: true
// A: [-2, 1, 3, 4]
// Answer: false
// 


bool hasTwoSumZero(vector<int> &A) {
	// add your logic here
	int n = A.size();
	int i=0;
	int j=n-1;
	
	while(i<j)
	{
		if(A[i]+A[j]==0)
		{
			return true;
		}
		else if(A[i]+A[j]<0)
		{
			i++;
		}
		else{
			j--;
		}
	}
	
	return false;
	
	
}