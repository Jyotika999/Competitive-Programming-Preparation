class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n2;i++)
        {
            mp[nums2[i]]=i;
        }
        
        vector<int>ans(n1, 0);
        vector<int>nge(n2, 0);
        // next greater element to right of nums2 array 
        stack<int>s;
        for(int i=n2-1;i>=0;i--)
        {
            if(s.empty())
                nge[i]=-1;
            else
            {
                while(!s.empty() and s.top()<=nums2[i])
                    s.pop();
                
                if(s.empty())
                    nge[i]=-1;
                else
                    nge[i]=s.top();
            }
            s.push(nums2[i]);
        }
        
        // for(int i=0;i<n2;i++)
        //     cout<<nge[i]<<" ";
        
        for(int j=0;j<n1;j++)
        {
            int ind = mp[nums1[j]];
            cout<<ind<<"\n";
            ans[j]=nge[ind];
            
        }
        
        return ans;
        
        
        
    }
};