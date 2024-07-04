#include <bits/stdc++.h> 

vector<int> minHeap(int n, vector<vector<int>>& q) {

    // Write your code here.

    priority_queue<int , vector<int> , greater<int>> pq ;

    vector<int> res;

    int i = 0 , value = -1;

    while(i < n){

        if(q[i][0] == 0) pq.push(q[i][1]);

        else {

            int value = pq.top();

            pq.pop();

            res.push_back(value);
        };

        i++;
    }

    return res;
}
