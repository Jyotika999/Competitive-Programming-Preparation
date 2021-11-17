int solve(vector<int>& nums, int target) {
    
    int n = nums.size();

 
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid = (low+high)/2;

        if(nums[mid]==target)
        {
            ans = mid+1;
            low=mid+1;
        }
       else if(nums[mid]<target)
       {
           low = mid+1;
       }
       else
       {
           high = mid-1;
       }
    }
    //return ans;
    return min(ans, high+1);
}