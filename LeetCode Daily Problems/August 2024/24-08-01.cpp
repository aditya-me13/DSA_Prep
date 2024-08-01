// Problem Link : https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(const string s:details){
            if(stoi(s.substr(11, 2)) > 60) count++;
        }
        return count;
    }
};