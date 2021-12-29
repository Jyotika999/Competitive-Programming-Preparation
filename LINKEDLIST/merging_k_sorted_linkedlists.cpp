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
    
    ListNode * merge(ListNode * l1, ListNode * l2)
    {
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        if(l1->val < l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        int n=lists.size();
        
        // since maximum value in list is 10^4 and minimum value is -10^4
        // hence we can keep dummy node as smalll as possible, which will not be present as a value in any of the node of the linkedlist 
        ListNode* dummy = new ListNode(-100000);
//         ListNode * prev=NULL;
        
        
//        if(lists.size())
//            prev=lists[0];
        
//         dummy->next=prev;
        
        
        for(int i=0;i<n;i++)
        {
            dummy= merge(dummy, lists[i]);
        }
        return dummy->next;
    }
};