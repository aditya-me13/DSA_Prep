class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){return nums[0];}
        int low = 0;
        int high = n - 1;
        int mid=0;

        while(high - low >= 2){
            mid = (high + low)/2;
            if(mid == 0 || mid == n - 1){
                return nums[mid];
            }
            if(mid%2){
                if(nums[mid - 1] == nums[mid]){
                    low = mid+1;
                    
                }
                else if(nums[mid + 1] == nums[mid]){
                    high = mid;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if(nums[mid - 1] == nums[mid]){
                    high = mid - 1;
                    
                }
                else if(nums[mid + 1] == nums[mid]){
                    low = mid;
                }
                else{
                    return nums[mid];
                }
            }
        }
        return nums[low];
    }
};
