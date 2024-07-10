// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int min_ = nums[0];

        while(low <= high){
            
            if(nums[low] < nums[high]){
                min_ = min(min_, nums[low]);
                return min_;
            }

            int mid = (low+high)/2;

            min_ = min(min_, nums[mid]);

            // find the half that is sorted
            if(nums[low]<=nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return min_;
    }
};