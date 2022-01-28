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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1==NULL and root2==NULL)
            return NULL;
        
        TreeNode * cur = new TreeNode(0);
        
        if(root1==NULL)
        { 
           cur->val = cur->val + root2->val;
           cur->left = mergeTrees(root1, root2->left);
           cur->right = mergeTrees(root1, root2->right);
           return cur;
        }
        
        else if(root2==NULL)
        {
            cur->val = cur->val + root1->val;
            cur->left = mergeTrees(root1->left, root2);
            cur->right = mergeTrees(root1->right, root2);
            return cur;
        }
        else
        {
            cur->val = cur->val + root1->val + root2->val;
            cur->left = mergeTrees(root1->left, root2->left);
            cur->right = mergeTrees(root1->right, root2->right);
            return cur;
        }
        
    }
};