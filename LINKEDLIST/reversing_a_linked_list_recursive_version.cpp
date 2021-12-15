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
    
    
    ListNode * reverse(ListNode * head)
    {
        // base case
        if(head->next==NULL)
        {
            return head;
        }
        
        // yeh sari bachee huyi list ko reverse krke dega
        ListNode * reverse_head = reverse(head->next);
        
        // ab sirf head wale link ko reverse krna h
        ListNode * temp=head->next;
        temp->next=head;
        head->next=NULL;
        
        // finally returning the reversed head
        return reverse_head;
        
    }
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)
        {
            return head;
        }
        return reverse(head);
    }
};