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
    
    vector<TreeNode*>v;
    map<string,int>mp;
    string helper(TreeNode*root)
    {
         if(root==NULL)
           return "";
        
        
        // inorder traversal
        string s="";
        s+="(";
        s+=helper(root->left);
        s+= to_string(root->val);
        s+= helper(root->right);
        s+=")";
        
        if(mp[s]==1)
        {
            
            v.push_back(root);
        }
        mp[s]++;
        return s;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
      helper(root);
        return v;
        
    }
};