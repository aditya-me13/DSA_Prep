class Solution{   
public:
    int ub(vector<vector<int>> &mat, int val){
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            ans += (upper_bound(mat[i].begin(), mat[i].end(), val) - mat[i].begin());
        }
        return ans;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int low = INT_MAX, high = INT_MIN;
        
        for(int i = 0; i< R; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C-1]);
        }
        int mid;
        int req = (R*C)/2;
        while(low <= high){
            mid = (low + high)/2;
            
            int no_lesser_equal = ub(matrix, mid);
            if(no_lesser_equal <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
