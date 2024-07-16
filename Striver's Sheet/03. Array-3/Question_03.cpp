class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Voting Algorithm
        int elem = -1, count = 0;       
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                elem = nums[i];
                count ++;
            }
            else if(elem == nums[i]) count++;
            else count--;
        }
        return elem;
    }
};