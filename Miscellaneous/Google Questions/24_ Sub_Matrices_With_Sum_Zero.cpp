// Problem Link: https://www.naukri.com/code360/problems/sub-matrices-with-sum-zero_1102321?topList=top-google-coding-interview-questions&leftPanelTab=1&leftPanelTabValue=PROBLEM
// Courtesy: https://www.youtube.com/watch?v=43DRBP2DUHg

#include <bits/stdc++.h>
using namespace std;

int subMatrices(vector<vector<int>> &mat, int n) {
    int count = 0;
    
    for (int rowStart = 0; rowStart < n; ++rowStart) {
        vector<int> temp(n, 0);
        
        for (int rowEnd = rowStart; rowEnd < n; ++rowEnd) {
    
            for (int col = 0; col < n; ++col) {
                temp[col] += mat[rowEnd][col];
            }
            
            unordered_map<int, int> prefix_sum_map;
            int current_prefix_sum = 0;
            

            prefix_sum_map[0] = 1;
            
            for (int col = 0; col < n; ++col) {
                current_prefix_sum += temp[col];
                
                if (prefix_sum_map.find(current_prefix_sum) != prefix_sum_map.end()) {
                    count += prefix_sum_map[current_prefix_sum];
                }
                
                prefix_sum_map[current_prefix_sum]++;
            }
        }
    }
    
    return count;
}