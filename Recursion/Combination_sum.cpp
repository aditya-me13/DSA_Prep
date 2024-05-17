class Solution {
public:
    void helper(int ind, int n, int target, vector<int> ss, vector<int> &nums, vector<vector<int>> &ans){
        if(target<0){
            return;
        }

        if(ind == n){
            if(target == 0) ans.push_back(ss);
            return;
        }

        if(target >= nums[ind]){
            ss.push_back(nums[ind]);
            helper(ind, n, target - nums[ind], ss, nums, ans);
            ss.pop_back();
        }
        helper(ind + 1, n, target, ss, nums, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ss;
        helper(0, candidates.size(), target, ss, candidates, ans);
        return ans;
    }
};
