class Solution {
public:
    #define PII pair<pair<int, int>, int>
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        queue<PII> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        // find all initially rotten oranges
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }   
            }
        }
        // max time required
        int tm = 0;
        int trows[4] = {0, +1, 0, -1};
        int tcols[4] = {+1, 0, -1, 0};
        int row, col, time, trow, tcol;
        while(!q.empty()){
            PII temp = q.front();
            q.pop();
            row = temp.first.first;
            col = temp.first.second;
            time = temp.second;
            
            for(int i = 0; i < 4; i++){
                trow = row + trows[i];
                tcol = col + tcols[i];
                if(trow >= 0 && trow < m && tcol>= 0 && tcol < n &&
                    !visited[trow][tcol] && grid[trow][tcol] == 1){
                    visited[trow][tcol] = 1;
                    q.push({{trow, tcol}, time + 1});
                }
            }
            tm = max(tm, time);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return tm;
    }
};