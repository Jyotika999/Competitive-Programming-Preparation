
bool func(vector<int>&nums, int mid, int k)
{
    int ct=1;
    int sum=0;

    for(int i=0;i<nums.size() ; i++)
    {
        if(nums[i]+sum<=mid)
        {
            sum += nums[i];
        }
        else
        {
            ct++;
            if(nums[i]>mid)
            return false;
            sum = nums[i];
        }
    }

if(ct<=k)
return true;
else
return false;



}

int solve(vector<int>& nums, int k) {
    

    int n = nums.size();

    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum = sum + nums[i];
    }

    int low=0;
    int high=sum;
    int ans=0;

    while(low<=high)
    {
        int mid = (low)+(high-low)/2;
        if(func(nums, mid, k)==true)
        {
            high = mid-1;
            ans = mid;
        }
        else
        {
            low = mid+1;
        }
    }
return ans;


}