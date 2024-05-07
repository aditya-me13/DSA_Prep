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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        int carry = 0, sum = 0;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while (l1 != nullptr) {
            sum = l1->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            temp = temp->next;
        }

        while (l2 != nullptr) {
            sum = l2->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2->next;
            temp = temp->next;
        }

        if (carry != 0) {
            temp->next = new ListNode(carry);
        }

        return newHead->next;
    }
};
