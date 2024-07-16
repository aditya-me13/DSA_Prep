class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==1){
                count += 1;
                max_ = max(count, max_);
            }
            else{
                count = 0;;
            }
        }
        return max_;
    }
};
