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
    ListNode* partition(ListNode* head, int x) {
        // return head;
        
        // the idea is to create to linkedlists
        // first list = store elements smaller than x
        // second list = store elements greater than or equal to x
        
        // join first list and second list
        
        ListNode * smaller=new ListNode(-1);
        ListNode * greater=new ListNode(-1);
        ListNode * smallptr=smaller;
        ListNode * greatptr=greater;
        
        while(head!=NULL)
        {
            if(head->val < x)
            {
                smaller->next= new ListNode(head->val);
                smaller=smaller->next;
            }
            else
            {
                greater->next = new ListNode(head->val);
                greater=greater->next;
            }
            head = head->next;
        }
        smaller->next=greatptr->next;
        return smallptr->next;
        
        
        
    }
};