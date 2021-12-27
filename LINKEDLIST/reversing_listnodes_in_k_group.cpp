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
    
    void reverse(ListNode * start, ListNode * endd)
    {
        ListNode * prev=NULL;
        ListNode * curr=start;
        ListNode * nextt=curr->next;
        
        
        while(prev!=endd)
        {
            curr->next = prev;
            prev=curr;
            curr=nextt;
            if(nextt!=NULL)
            nextt=nextt->next;
        }
        // return end;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // base case 
        // when the linkedlist is empty
        // linkedlist have only one node
        // reversing of the linkedlist takes place in groups of 1 = same linkedlist
        
        if(head==NULL || head->next==NULL || k==1)
            return head;
        
        // i will reverse the first k group 
        // and the k groups will get reversed by recursion itself
        
        ListNode * s=head;
        ListNode * e = head;
        
        // we will reverse the first k group , if we know the starting and ending position of the k group
        // so finding the ending position of this k group, by iterating the linkedlist
        int ct=k-1;
        while(ct--)
        {
            // ct--;
            // there might occur a condition, where end might point to NULL, so in that case, it means that the leftover group is of size which is less than k, in that case, we dont have to reverse the list, and simply return the head pointer of the linkedlist .
           // if(e==NULL) 
            e=e->next;
           if(e==NULL)
            return head;
        }
        
        // reverse the rest of the linkedlist
        ListNode * nexthead = reverseKGroup(e->next, k);
        
        // reverse the current group of linkedlist which is of size k
        reverse(s, e);
        
        // after the reversal , start will become end , and end will become start
        s->next = nexthead;
        
        return e;
        
        
        
    }
};