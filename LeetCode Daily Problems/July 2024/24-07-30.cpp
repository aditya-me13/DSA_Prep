// problem Link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pre(n);
        vector<int> suf(n);
        
        int count = 0;
        for(int i=0; i<n; i++){
            pre[i]=count;
            if(s[i]=='b') count ++;
        }

        count = 0;
        for(int i=n-1; i>=0; i--){
            suf[i]=count;
            if(s[i]=='a') count ++;
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, pre[i] + suf[i]);
        }

        return mini;
    }
};