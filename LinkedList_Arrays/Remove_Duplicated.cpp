class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, k = 0;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] != nums[k]){
                nums[k+1] = nums[i];
                k++;
            }
        }   
        return k+1;
    }
};
