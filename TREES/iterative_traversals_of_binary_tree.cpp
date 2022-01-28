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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>traversal;
        
        if(root==NULL)
            return traversal;
        
        stack<pair<TreeNode*, int>>s;
        
        s.push({root,1});
        while(!s.empty())
        {
            auto cur = s.top();
            auto curnode = cur.first;
            auto curstate = cur.second;
            
            if(curstate==1)
            {
                // preorder traversal 
                // state++
                // move to left
                s.top().second = curstate+1;
                if(curnode->left!=NULL)
                {
                    s.push({curnode->left, 1});
                }
            }
            else if(curstate==2)
            {
                // inorder traversal 
                // state++
                // move to right
                traversal.push_back(curnode->val);
                s.top().second = curstate+1;
                if(curnode->right!=NULL)
                {
                    s.push({curnode->right, 1});
                }
            }
            else if(curstate==3)
            {
                // postorder traversal 
                // pop the node
                s.pop();
                
                
            }
        }
        return traversal;
        
    }
};