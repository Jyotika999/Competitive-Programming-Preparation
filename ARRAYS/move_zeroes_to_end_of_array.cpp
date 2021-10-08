class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
    
//   int n = arr.size() - 1;
//   int left = 0;
//   for(int i=0; i<n; i++) {
//     if(arr[i]!= 0)arr[left++] = arr[i];
    
//   }
//        // cout<<left<<"\n";
        
      
//   while(left<n)arr[left++] = 0;
//  // return arr;
        
//     }
        
        
        
        
        int insertPos = 0;
    for (int num: nums) {
        if (num != 0) nums[insertPos++] = num;
    }        

    while (insertPos < nums.size()) {
        nums[insertPos++] = 0;
    }
    }
};