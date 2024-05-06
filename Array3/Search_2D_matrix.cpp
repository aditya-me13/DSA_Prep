class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // no of rows
        int n = matrix[0].size(); // no of cols
        int tr=-1;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] <= target){
                tr = i;
            }
            else{
                if (tr == -1){
                    return false;
                }
            }
        }

        for(int i = 0; i < n; i ++){
            if(matrix[tr][i] == target){
                return true;
            }
        }
        return false;

        
        // int m = matrix.size();
        // int n = matrix[0].size();
        // int row, col, mid, low = 0, high = m + n - 1;
        // while(low <= high){
        //     mid = (low+high)/2;
        //     row = mid / m;
        //     col = mid % n;
        //     if(row >= m || col >= n){
        //         return false;
        //     }
        //     if(matrix[row][col] == target) {return true;}
        //     else if(matrix[row][col] < target) {low = mid + 1;}
        //     else{high = mid -1;}
        // }
        // return false;
    }
};
