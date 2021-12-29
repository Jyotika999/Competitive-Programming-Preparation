/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode * left=head;
        ListNode * right=head;
        
        stack<int>s;
        
        while(right!=NULL)
        {
            s.push(right->val);
            right=right->next;
        }
        
        while(left!=NULL)
        {
            if(left->val == s.top())
            {
                left=left->next;
                s.pop();
            }
            else
                return false;
        }
        
        return true;
    }
};