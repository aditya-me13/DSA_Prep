// Problem : minimum average of smallest and largest elements
// Problem Link : https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/


class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() -1;
        
        double maxi = 101.0;
        while(low <= high){
            double temp = float(nums[high])/2.0 + float(nums[low])/2.0;
            if(maxi > temp) maxi = temp;
            low++;
            high--;
        }
        return maxi;
    }
};