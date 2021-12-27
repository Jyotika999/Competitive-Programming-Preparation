/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    // METHOD 1 
    // store the hashmap of nodes address , the one which will first match 
    // will be the first intersecting point of the two linkedlists
    // TIME COMPLEXITY : O(N+M)
    // SPACE COMPLEXITY : O(N+M)
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        map<ListNode*, int>mp;
        
        while(headA!=NULL)
        {
            mp[headA]++;
            headA = headA->next;
        }
        
        while(headB!=NULL)
        {
            if(mp[headB]!=0)
                return headB;
            
            mp[headB]++;
            headB = headB->next;
        }
        return NULL;
    }
};