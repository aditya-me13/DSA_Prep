Problem Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

class Solution {
private:
    void helper(int ind, int n, bool lastZero, string s,vector<string> &ans){
        if(ind == n){
            ans.push_back(s);
            return;
        }
        if(!lastZero){
            helper(ind+1, n, true, s+"0", ans);
        }
        helper(ind+1, n, false, s+"1", ans);
    }
public:
    vector<string> validStrings(int n) {
        if(n==1) return {"0", "1"};  
        vector<string> ans;
        helper(0,n,false,"",ans); 
        return ans;
    }
};