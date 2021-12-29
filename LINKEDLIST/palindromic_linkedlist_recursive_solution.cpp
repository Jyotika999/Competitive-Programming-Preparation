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


// doing this question of checking whether the linkedlist is palindrome or not, that too using recursion, is really a beautiful concept.

class Solution {
public:
    ListNode * left;
    
    bool check_palindrome(ListNode * right)
    {
        if(right==NULL)
            return true;
        
        bool further = check_palindrome(right->next);
        
        if(further==false)
            return false;
        if(right->val == left->val)
        {
            left=left->next;
            return true;
        }
        else
            return false;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        left=head;
        return check_palindrome(head);
        
        
        
        
    }
};