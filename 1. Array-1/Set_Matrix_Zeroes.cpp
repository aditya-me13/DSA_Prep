class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row_marked(m,0);
        vector<int> col_marked(n,0);
        for (int i = 0; i< n; i++){
            for (int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    row_marked[j] = 1;
                    col_marked[i] = 1;
                    }
                }
            }

        for (int i = 0; i< n; i++){
            for (int j = 0; j<m; j++){
                if(row_marked[j] == 1 || col_marked[i] == 1){
                    matrix[i][j] = 0;
                }
            } 
    }
}
};
