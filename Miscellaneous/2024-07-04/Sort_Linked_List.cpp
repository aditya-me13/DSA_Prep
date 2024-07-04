// Problem Link: https://leetcode.com/problems/sort-list/description/

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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* itr = head;
        
        while(itr){
            arr.push_back(itr->val);
            itr = itr->next;
        }

        sort(arr.begin(), arr.end());

        itr = head;
        int i=0;
        while(itr){
            itr->val = arr[i];
            i++;
            itr=itr->next;
        }

        return head;
    }
};