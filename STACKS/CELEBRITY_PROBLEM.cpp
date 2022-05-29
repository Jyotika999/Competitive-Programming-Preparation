// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        while(s.size()>1)
        {
            int ff = s.top();
            s.pop();
            int ss=-1;
           
            ss = s.top();
            s.pop();
            
         
            
            if(M[ff][ss]==1)
            {
             // ff knows ss
             // means ff cannot be celebrity
             s.push(ss);
            }
            else
            {
                // ff does not know ss
                // ss cant be celebrity
             s.push(ff);   
            }
        }
        
        // ab stack m jo ek element hai 
        // verify kro ab 
        // ki current person is knwn by everyone 
        // but current person does not know anyone
        
        for(int i=0;i<n;i++)
        {
            // cout<<i<<" "<<s.top()<<"\n";
            if(i!=s.top())
            {
                if(M[i][s.top()]==1 and M[s.top()][i]==0)
                {
                    continue;
                }
                else
                return -1;
            }
        }
        
        return s.top();
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends