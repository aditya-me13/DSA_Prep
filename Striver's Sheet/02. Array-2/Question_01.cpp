class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++)
              // Use more inbuilt functions as they are faster
                swap(arr[i][j], arr[j][i]);
        }

        for(int i=0; i<n; i++)
          // Use more inbuilt functions as they are faster
            reverse(arr[i].begin(), arr[i].end());
    }
};
