#include <bits/stdc++.h> 
#define PII  pair<int, pair<int, int>>

struct compare {
    bool operator()(const PII& p1, const PII& p2) {
        return p1.first > p2.first; // Min-heap based on the first element
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<PII, vector<PII>, compare> minHeap;

    for(int i = 0; i < k; i++){
        minHeap.push({kArrays[i][0], {i, 0}});
    }

    vector<int> ans;
    PII curr;
    int arr_no, curr_ind;

    while(k != 0){
        curr = minHeap.top();
        minHeap.pop();
        ans.push_back(curr.first);
        arr_no = curr.second.first;
        curr_ind = curr.second.second;    
        
        if(kArrays[arr_no].size() - 1 == curr_ind){
            k--;
        }
        else{
            minHeap.push({kArrays[arr_no][curr_ind+1], {arr_no, curr_ind + 1}});
        }
        
    }
    return ans;
}
