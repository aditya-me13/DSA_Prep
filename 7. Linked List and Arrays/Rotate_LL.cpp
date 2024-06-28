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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* itr1 = head, *itr2 = head;
        int count = 0;
        while(itr2!=NULL){
            itr2 = itr2->next;
            count ++;
        }

        k = k%count;
        for(int i = 0; i < k ; i++){
            itr1 = itr1->next;
           if(itr1 == NULL){
                itr1 = head;
            }
        }

        if(itr1 == head){
            return head;
        }

        itr2 = head;
        while(itr1->next != NULL){
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
        itr1->next = head;
        head = itr2->next;
        itr2->next = NULL;

        return head;
    }
};
