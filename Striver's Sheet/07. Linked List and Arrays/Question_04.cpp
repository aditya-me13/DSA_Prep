class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2){
            return 0;
        }

        vector<int> max_lefts(n, 0);
        vector<int> max_rights(n, 0);

        for(int i = 1; i < n; i++){
            max_lefts[i] = max(max_lefts[i-1], height[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            max_rights[i] = max(max_rights[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(0, min(max_lefts[i], max_rights[i]) - height[i]);
        }

        return ans;
    }
};