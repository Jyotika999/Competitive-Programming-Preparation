class Solution {
public:
     
        // observation:
//         the indices where we need to make a swap,
//         if a,b  and b,c 
//             then we can interchangeably swap a,b,c
//         this means a,b,c will form one connceted component
//         the characters in each component will be sorted , to make it lexcigraphically sorted
//         then merging the sorted characters of every connected component and finally we get the lexicographically smallest string possible
            
//             we will make use of DSU's to make connected components
         
    int parent[100005];
    int rank[100005];
    
    int find_parent(int i)
    {
        if(i==parent[i])
            return i;
        return parent[i] = find_parent(parent[i]);
    }
      
    void unionn(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        
        if(a!=b)
        {
            if(rank[a]<rank[b])
            {
                parent[a]=b;
            }
            else if(rank[a]>rank[b])
            {
                parent[b]=a;
            }
            else
            {
                parent[a]=b;
                rank[b]++;
            }
        }
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
       
        int len = s.length();
        int n = pairs.size();
        
        for(int i=0;i<len;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
        
        for(int i=0;i<n;i++)
        {
            int u = pairs[i][0];
            int v = pairs[i][1];
            
            if(find_parent(u)!=find_parent(v))
            {
                unionn(u, v);
            }
        }
        map<int, string>mp;
        map<int, vector<int>>ind;
        string ans=s;
        
        for(int j=0;j<len;j++)
        {
            // yhan mistake mat krna ;-;
            int p = find_parent(j);
            // cout<<j<<" "<<p<<"\n";
            mp[p]+=s[j];
            ind[p].push_back(j);
        }
        vector<string>v;
        for(auto it : mp)
        {
            string s2 = it.second;
            vector<int>i = ind[it.first];
            sort(i.begin(), i.end());
            sort(s2.begin(), s2.end());
            cout<<it.first<<" "<<s2<<" ";
            
            for(int j=0;j<i.size();j++)
            {
                cout<<i[j]<<" ";
                ans[i[j]] = s2[j];
            }
            // v.push_back(s2);
            cout<<"\n";
        }
      
        return ans;
        
        
    }
};