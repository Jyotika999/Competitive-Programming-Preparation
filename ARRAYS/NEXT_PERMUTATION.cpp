class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int index1=-1;
        int index2=-1;
        int n = nums.size();
        
        // finding index 1 , jis element ko bda kr skte ho aap 
        // toh peeche se check krenge 
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index1 = i;
                break;
            }
        }
        
        
        // handling the edge case , if index1 = -1 , means no smaller element, so in that case , make the array increaing 
        if(index1 == -1)
        {    reverse(nums.begin(), nums.end());
        return;
        }
        // finding index 2 , jo index1 wale element se just bda ho 
        
        for(int i=n-1;i>index1;i--)
        {
            if(nums[i]>nums[index1])
            {
                if(index2==-1)
                index2 = i;
                else
                {
                    // becaoz hmein just bda wala element chahiye 
                    if(nums[index2]<nums[i])
                        continue;
                    else
                        index2 = i;
                }
            }
        }
        
        
        // swapping index1 and index 2 
        swap(nums[index1], nums[index2]);
        
        // remaining elements ko sort krdenge 
        sort(nums.begin()+index1+1, nums.begin()+n);
        
        
        
        
        
        
    }
};
