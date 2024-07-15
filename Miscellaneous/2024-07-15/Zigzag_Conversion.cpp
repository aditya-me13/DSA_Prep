// Problem Link: https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<int> arr[numRows];
        int n = s.size();

        int j = 0;
        bool rev = false;

        for(int i=0; i<n; i++){
            arr[j].push_back(s[i]);
            if(j==numRows-1){
                rev = true;
            }
            if(j==0){
                rev = false;
            }
            rev == true ? j--: j++;
        }

        j = 0;
        string ans(n, ' ');
        for(vector<int> ar: arr){
            for(int c:ar){
                ans[j] = c;
                j++;
            }
        }
        return ans;
    }
};