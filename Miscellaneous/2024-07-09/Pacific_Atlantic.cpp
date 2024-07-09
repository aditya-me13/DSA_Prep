// Problem Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
private:
    void dfs_pacific(vector<vector<int>> &grid, int row , int col, vector<vector<pair<int,int>>> &visited, int prev){
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col].first || grid[row][col] < prev) {
            return;
        }
        
        visited[row][col].first = 1;
        
        dfs_pacific(grid, row - 1, col, visited, grid[row][col]);
        dfs_pacific(grid, row + 1, col, visited, grid[row][col]);
        dfs_pacific(grid, row, col - 1, visited, grid[row][col]);
        dfs_pacific(grid, row, col + 1, visited, grid[row][col]);
    }

    void dfs_atlantic(vector<vector<int>> &grid, int row , int col, vector<vector<pair<int,int>>> &visited, int prev){
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col].second || grid[row][col] < prev) {
            return;
        }
        
        visited[row][col].second = 1;
        
        dfs_atlantic(grid, row - 1, col, visited, grid[row][col]);
        dfs_atlantic(grid, row + 1, col, visited, grid[row][col]);
        dfs_atlantic(grid, row, col - 1, visited, grid[row][col]);
        dfs_atlantic(grid, row, col + 1, visited, grid[row][col]);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<pair<int,int>>> vis(m,vector<pair<int,int>>(n,{0,0}));
        vector<vector<int>> ans;

        // treverse form pecific
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j== 0){
                    dfs_pacific(heights,i,j,vis,heights[i][j]);
                }
            }
        }

        // treverse atlantic 
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 || j== n-1){
                    dfs_atlantic(heights,i,j,vis,heights[i][j]);
                }
            }
        }

        // check which has both one `
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j].first == 1 && vis[i][j].second ==1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};