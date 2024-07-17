class Solution {
public:
    void helper(int row, int col, int n, vector<vector<int>> &mat, vector<string>&all, string&route){
        if(row<0 || col<0 || row>=n || col>=n || mat[row][col]==0){
            return;
        }
        
        if(row==n-1 && col==n-1){
            all.push_back(route);
            return;
        }
        
        int r[] = {0, +1, 0, -1};
        int c[] = {+1, 0, -1, 0};
        char m[] = {'R', 'D', 'L', 'U'};
        
        for(int i=0; i<4; i++){
            route.push_back(m[i]);
            mat[row][col]=0;
            helper(row + r[i], col+c[i], n, mat, all, route);
            mat[row][col]=1;
            route.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> allRoutes;
        int n=mat.size();
        string route = "";
        helper(0, 0, n, mat, allRoutes, route);
        return allRoutes;
    }
};