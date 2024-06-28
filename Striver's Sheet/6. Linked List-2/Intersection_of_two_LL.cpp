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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Form a cycle if intersection exists
        ListNode* slow = headA;
        ListNode* fast = headA;
        ListNode* itr = headA;

        while(itr->next != NULL){
            itr = itr->next;
        }
        itr->next = headB;

        // Detect the start of the cycle
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = headA;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                itr->next = NULL;
                return slow;
            }
        }
        itr->next = NULL;
        return NULL;
    }
};
