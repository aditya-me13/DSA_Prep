// Problem Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2024-07-05

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        bool firstfound = false;
        int first;
        int last;
        int mingap = INT_MAX;
        ListNode* front = head->next;
        ListNode* back = head;

        int i=1;
        while(front->next){
            if((front->val > back->val) && (front->val > front->next->val)){
                if(!firstfound) {
                    first = i;
                    firstfound = true;
                }
                else{
                    mingap = min(mingap, i-last);
                    }
                last = i;
            }
            else if((front->val < back->val) && (front->val < front->next->val)){
                if(!firstfound) {
                    first = i;
                    firstfound = true;
                }
                else{
                    mingap = min(mingap, i-last);
                }
                last = i;
            }
            i++;
            front = front->next;
            back = back->next;
        }


        if(firstfound && first != last) return {mingap, last-first};
        return{-1, -1};
    }
};