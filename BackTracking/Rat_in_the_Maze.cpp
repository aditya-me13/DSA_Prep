    public:
    
    void helper(int n, int row, int col, vector<vector<int>> &maze, string path, vector<string> &ans) {

        if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0) {
            return;
        }


        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        maze[row][col] = 0;

        // Move Down
        helper(n, row + 1, col, maze, path + 'D', ans);
        // Move Right
        helper(n, row, col + 1, maze, path + 'R', ans);
        // Move Up
        helper(n, row - 1, col, maze, path + 'U', ans);
        // Move Left
        helper(n, row, col - 1, maze, path + 'L', ans);

        // Backtrack
        maze[row][col] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> ans;
        string path;
        helper(n, 0, 0, maze, path, ans);
        return ans;
    }
};
