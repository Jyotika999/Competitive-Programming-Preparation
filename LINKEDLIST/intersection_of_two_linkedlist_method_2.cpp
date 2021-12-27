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
    
    // method 2 
    // USING THE LINKEDLIST TRAVERSAL 
    // SINCE THERE ARE TWO LINKEDLISTS 
    // first calculating the length of linkedlist 1 (say its len1)
    // then calculate the length of linkedlist 2 , (say its len2)
    // then traverse the bigger linkedlist by (len1-len2)
    // then traverse both the linkedlists together until they intersect
    
    // TIME : O(N+M)
    // space : O(1)
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        ListNode * t1 = headA;
        ListNode * t2 = headB;
        
        int len1=0;
        int len2=0;
        
        while(t1!=NULL)
        {
            len1++;
            t1 = t1->next;
        }
        
        while(t2!=NULL)
        {
            len2++;
            t2 = t2->next;
        }
        int dif = abs(len1-len2);
        
        if(len1>len2)
        {
            // then traverse linkedlist 1 , which is bigger in size
            t1 = headA;
            t2=headB;
            while(dif)
            {
                 t1 = t1->next;
                dif--;
            }
            
            
        }
        else
        {
            // traverse linkedlist 2 , which is bigger in size 
            t2 = headB;
            t1 = headA;
            while(dif)
            {
                t2 = t2->next;
                dif--;
            }
            
        }
        
        while(t1!=NULL and t2!=NULL)
        {
            if(t1==t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
            
        }
        
        return NULL;
        
        
        
        
    }
};