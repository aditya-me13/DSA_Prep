class Solution {
public:
    void helper(int ind, int n, int target, vector<int> &nums, vector<int> ss,vector<vector<int>> & ans){
        if(target == 0){
            ans.push_back(ss);
            return;
        }

        for(int i = ind; i<n; i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            if(target < nums[i]) break;
            ss.push_back(nums[i]);
            helper(i+1, n, target - nums[i], nums, ss, ans);
            ss.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ss;
        helper(0, nums.size(), target, nums, ss, ans);
        return ans;
    }
};
