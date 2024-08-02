// Problem Link : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int n:nums){
            if(n==1) ones++;
        }   

        int ans = 0;

        for(int i=0; i<ones; i++){
            if(nums[i]==0) ans++;
        }

        int mini = ans;

        for(int i=0; i<n; i++){
            if(nums[i]==0) ans--;
            if(nums[(i+ones)%n]==0) ans++;
            mini = min(mini, ans);
        }

        return mini;
    }
};