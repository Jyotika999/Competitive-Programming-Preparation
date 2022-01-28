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
            
    vector<int>traversal;
    
    void postorder(TreeNode * root)
    {
        if(root==NULL)
            return;
        
        // left 
        if(root->left!=NULL)
        postorder(root->left);
        // right
        if(root->right!=NULL)
        postorder(root->right);
        // root
        traversal.push_back(root->val);
        
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
    
        if(root==NULL)
            return traversal;
        
        // postorder : leftchild, rightchild, root
        
        postorder(root);
      return traversal;
        
    }
};