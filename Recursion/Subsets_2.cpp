class Solution {
public:
    void ss(int ind, int n, vector<int> nums, vector<int> subset, set<vector<int>> & pow){
        if(ind == n){
            pow.insert(subset);
            return;
        }

        // do not select
        ss(ind +1, n, nums, subset, pow);

        // select
        subset.push_back(nums[ind]);
        ss(ind + 1, n, nums, subset, pow);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> pow;
        vector<int> subset;
        ss(0, nums.size(), nums, subset, pow);
        vector<vector<int>> pow_(pow.begin(), pow.end());
        return pow_;
    }
};
