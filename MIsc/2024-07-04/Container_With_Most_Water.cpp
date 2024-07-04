// Prolem Link: https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {     
        int left = 0;
        int right = height.size()-1;
        int ans = 0;

        while(left < right){
            int l = height[left];
            int r = height[right];

            if(l < r){
                ans = max(ans, (right-left)*l);
                left++;
            }
            else{
                ans = max(ans, (right-left)*r);
                right--;
            }
        }
        return ans;
    }
};