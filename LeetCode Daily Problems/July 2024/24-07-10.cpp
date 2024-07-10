// Problem Link: https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr = 0;
        for(string log:logs){
            if(log[0]=='.'){
                if(log[1]=='.'){
                    curr = (curr==0) ? 0: curr-1;
                }
            }
            else{
                curr++;
            }
        }
        return curr;
    }
};