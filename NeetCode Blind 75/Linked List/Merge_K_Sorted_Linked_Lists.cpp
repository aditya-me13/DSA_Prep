// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/

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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }

        ListNode* newHead;

        if(list1->val < list2->val){
            newHead = list1;
            list1 = list1->next;
        }

        else{
            newHead = list2;
            list2 = list2->next;
        }
        
        ListNode* temp = newHead;
        while(list1 != NULL && list2 != NULL){
            if(list1->val > list2->val){
                temp->next = list2;
                list2 = list2->next;
            }  
            else{
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;
        }

        if(list1 == NULL){
            temp->next = list2;
            return newHead;
        }
        else{
            temp->next = list1;
            return newHead;
        }   
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];

        while(n > 1){
            vector<ListNode*> temp(0);
            for(int i=0; i<n; i+=2){
                ListNode* one = lists[i];
                ListNode* two = nullptr;
                
                if(i+1 < n) two = lists[i+1];

                temp.push_back(mergeTwoLists(one, two));
            }
            lists = temp;
            n=lists.size();
        }

        return lists[0];
    }
};