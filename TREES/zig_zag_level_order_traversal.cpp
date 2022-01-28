/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>traversal;
        if(root==NULL)
            return traversal;
        queue<TreeNode*>q;
        q.push(root);
        int flag=1;
        
        while(!q.empty())
        {
            int n = q.size();
            
             vector<int>temp;
            while(n--)
            {
               
                auto cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                
                if(cur->left!=NULL)
                    q.push(cur->left);
                
                if(cur->right!=NULL)
                    q.push(cur->right);
           
            }
                 
                if(flag)
                {
                    traversal.push_back(temp);
                    flag=0;
                }
                else
                {
                    reverse(temp.begin(), temp.end());
                    traversal.push_back(temp);
                    flag=1;
                }
        }
        
        return traversal;
        
    }
};