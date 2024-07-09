// Problem Link: https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        vector<int> waitTime(n, 0);
        int completeTime = customers[0][0];

        for(int i=0; i<n; i++){
            // orders after the previous is prepared
            if(completeTime < customers[i][0]){
                waitTime[i] = customers[i][1];
                completeTime = customers[i][0] + customers[i][1];
            }
            // orders before
            else{
                waitTime[i] = customers[i][1] + (completeTime - customers[i][0]);
                completeTime += customers[i][1];
            }
        }

        double ans = 0.0;
        for(int val: waitTime){
            ans += val;
        }

        return ans/n;
    }
};