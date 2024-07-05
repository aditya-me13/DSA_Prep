// 
// Problem Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* curr = head->next;

        while(curr->next){
            if(curr->val == 0){
                temp = temp->next;
                temp->val=0;
            }
            else{
                temp->val += curr->val;
            }
            curr = curr->next;
        }
        temp->next = NULL;

        return head;
    }
};