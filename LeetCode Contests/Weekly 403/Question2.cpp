// Problem : find the minimum area to cover all ones
// Problem Link : https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<bool> hash_row(n, false);
        vector<bool> hash_col(m, false);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    hash_row[i]=true;
                    hash_col[j]=true;
                }
            }
        }
        
        int low = n; int high = -1;
        for(int i=0; i<n; i++){
            if(i < low && hash_row[i]==true){
                low = i;
            }
            if(i > high && hash_row[i]==true){
                high = i;
            }
        }
        
        int low_ = m; int high_ = -1;
        for(int i=0; i<m; i++){
            if(i < low_ && hash_col[i]==true){
                low_ = i;
            }
            if(i > high_ && hash_col[i]==true){
                high_ = i;
            }
        }
        
        return (high-low+1)*(high_-low_+1);
        
    }
};