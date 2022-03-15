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
    
    map<TreeNode*, int>mp;
    int solve(TreeNode * root)
    {
         if(root==NULL)
            return 0;
        
        if(mp[root]!=0)
            return mp[root];
        int leftgrandchild =0;
        int rightgrandchild =0;
        if(root->left!=NULL)
            leftgrandchild = solve(root->left->left) +  solve(root->left->right);
        if(root->right!=NULL)
            rightgrandchild = solve(root->right->left) + solve(root->right->right);
        
        // rob current node, rob its grandchildren subtree if any
        int yesrob = root->val + leftgrandchild + rightgrandchild;
        
        // dont rob current node, rob its children subtree if anny
        int norob = solve(root->left)+ solve(root->right);
        
        return mp[root]=max(yesrob, norob );
        
    }
    int rob(TreeNode* root) {
    
        
        return solve(root);
       
    }
};