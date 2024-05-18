class Solution {
public:
    void helper(vector<int> arr, int itr, vector<vector<int>> &ans, int n){
        if (itr == n){
            ans.push_back(arr);
            return;
        }
        for(int i = itr; i < n; i++){
            swap(arr[itr], arr[i]);
            helper(arr, itr+1, ans, n);
            swap(arr[itr], arr[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, 0, ans, nums.size());
        return ans;
    }
};
