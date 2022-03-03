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
    
    
    
    void solve(ListNode * l1, ListNode * l2, int carry, ListNode * l3)
    {
        if(carry!=0 and l1==NULL and l2==NULL)
        {
            ListNode * newnode = new ListNode(carry);
            l3->next = newnode;
            l3 = l3->next;
            return;
        }
        if(l1==NULL and l2==NULL)
        {
            
            l3->next = NULL;
            return;
        }
        if(l1!=NULL and l2==NULL)
        {
            int cursum = l1->val + carry;
            ListNode * newnode = new ListNode(cursum%10);
            l3->next = newnode;
            l3 = l3->next;
            carry = cursum/10;
            solve(l1->next, l2, carry, l3);
        }
        if(l2!=NULL and l1==NULL)
        {
            int cursum = l2->val + carry;
            ListNode * newnode = new ListNode(cursum%10);
            l3->next = newnode;
            l3 = l3->next;
            carry = cursum/10;
            solve(l1, l2->next, carry, l3);
        }   
        
        if(l1!=NULL and l2!=NULL)
        {
            int cursum = l1->val + l2->val + carry;
            ListNode * newnode = new ListNode(cursum%10);
            l3->next = newnode;
            l3 = l3->next;
            carry = cursum/10;
            solve(l1->next, l2->next, carry, l3);
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode  * l3 = new ListNode(-1);
        ListNode * temp = l3;
        solve(l1, l2, 0, l3);
        
        // while(temp!=NULL)
        // {
        //     cout<<temp->val<<"\n";
        //     temp= temp->next;
        // }
        return temp->next;
        
            
        
        
        
        
    }
};