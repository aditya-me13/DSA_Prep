class Solution {
public: 
    // function to check if it's a palindrome
    bool isPal(string s, int start, int end){
        while(start < end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    // recursive function for palindrome partioning
    void pp(int ind, vector<string> &str, string s, vector<vector<string>>& ans){
        if(s.size() == ind){
            ans.push_back(str);
            return;
        }

        for(int i = ind; i<s.size(); ++i){
            if(isPal(s, ind, i)){
                str.push_back(s.substr(ind, i - ind + 1)); 
                pp(i+1, str, s, ans);
                str.pop_back();
            }
        }
    }

    // main driver function
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        pp(0, str, s, ans);
        return ans;
    }
};
