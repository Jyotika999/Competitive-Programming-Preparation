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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode * dummy = new ListNode(-1);
        
        ListNode * prev = dummy;
        dummy->next = head;
        ListNode * cur = head;
        
        while(cur!=NULL)
        {
            if(cur->val == val)
            {
                prev->next = cur->next;
            }
            else
            prev=cur;
            
            cur=cur->next;
        }
        
        // cout<<prev->val<<" ";
        // cout<<cur->val<<"\n";
      //  prev->next = cur->next;
    //    delete(cur);
        
        ListNode * tmp = head;
        
        while(tmp!=NULL)
        {
            cout<<tmp->val<<"\n";
            tmp = tmp->next;
        }
        
        return dummy->next;
        
    }
};