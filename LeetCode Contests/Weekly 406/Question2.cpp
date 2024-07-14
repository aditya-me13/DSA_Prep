// Problem Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num] = 1;
        }

        while(true){
            if(mp.find(head->val) == mp.end()){
                break;
            }
            else{
                head = head->next;
            }
        }
        ListNode *prev, *curr;
        curr = head->next;
        prev = head;

        while(curr){
            if(mp.find(curr->val) != mp.end()){
                prev->next = prev->next->next;
            }
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return head;
    }
};