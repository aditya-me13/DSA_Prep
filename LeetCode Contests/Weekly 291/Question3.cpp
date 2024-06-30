// Problem Link: https://leetcode.com/problems/k-divisible-elements-subarrays/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();

        set<vector<int>> st;

        for(int i=0; i<n; i++){
            int count = 0;
            vector<int> curr;

            for(int j=i ; j<n; j++){
                curr.push_back(nums[j]);

                if(nums[j] % p == 0){
                    count++;
                }

                if(count <= k){
                    st.insert(curr);
                }    
                else{
                    break;
                }
            }
        }
        return st.size();
    }
};