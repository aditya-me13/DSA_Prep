// Problem Link:https://leetcode.com/problems/reorder-list/

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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = nullptr, *temp;
        while(head != nullptr){
            temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
public:
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* temp,temp2;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        temp = slow->next;
        slow->next = nullptr;
        slow = reverseList(temp);
        fast = head;

        while(slow){
            temp = fast->next;
            fast->next = slow;
            fast = temp;

            temp = slow->next;
            slow->next = fast;
            slow = temp;
        }
    }
};