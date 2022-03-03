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
    
    void solve(ListNode * list, int val, ListNode* prev)
    {
        if(list==NULL)
            return ;
        
        if(list->val == val)
        {
            ListNode * temp = new ListNode(list->val);
            prev->next = list->next;
            delete(temp);
            solve(list->next , val, prev);
        }
        else
        {
            prev = list;
            list = list->next;
            solve(list, val, prev);
        }            

    }
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        
        
        solve(head, val, dummy);
        return dummy->next;
    }
};