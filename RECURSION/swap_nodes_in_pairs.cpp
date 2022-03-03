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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        
        // aage ki bachee huyi sari linkedlist ko reverse krke leke aayo
        ListNode * aage = swapPairs(head->next->next);
        
        // abhi k 2 nodes ko hum reverse kr denge 
        ListNode * temp1 = head->next;
        ListNode * temp = head;
        temp1->next = temp;
        temp->next = aage;
        
        // start of linkedlist retirn krdo 
        return temp1;
        
    }
};