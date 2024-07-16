class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums2;
        for(int i = 0; i < nums.size(); i++){
            nums2.push_back({nums[i], i});
        }

        sort(nums2.begin(), nums2.end());
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            if(nums2[left].first + nums2[right].first == target){
                return {nums2[left].second, nums2[right].second};
            }
            else if(nums2[left].first + nums2[right].first > target){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1,-1};
    }
};