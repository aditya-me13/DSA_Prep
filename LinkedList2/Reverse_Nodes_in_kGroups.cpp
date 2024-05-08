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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        // Initiate all pointers
        ListNode* itr = head;
        ListNode* dummy;
        ListNode* curr;
        ListNode* prev = new ListNode(0, head);;
        

        // Count number of nodes
        int num = 0;
        while (itr != NULL) {
            itr = itr->next;
            num++;
        }
        // number of flips required
        num = num / k;

        for (int i = 0; i < num; i++) {
            dummy = curr;
            curr = prev->next;
            itr = curr->next;

            for(int l = 0; l < k-1; l++){
                curr->next = itr->next;
                itr->next = prev->next;
                prev->next = itr;
                itr = curr->next;
            }

            if(i == 0){
                head = prev->next;
            }
            dummy->next = prev->next;
            prev->next = itr;
            

        }
        return head;
    }
};
