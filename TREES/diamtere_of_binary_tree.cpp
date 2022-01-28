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
    
    int solve(TreeNode * root, int &maxdis)
    {
        if(root==NULL)
            return 0;
        
        int lh = solve(root->left, maxdis);
        int rh = solve(root->right, maxdis);
        
        maxdis = max(maxdis, lh+rh);
        return max(lh, rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int maxdis = 0;
        solve(root, maxdis);
        return maxdis;
        
    }
};