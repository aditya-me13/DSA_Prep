class Solution {
  public:
    void SSsum(int ind, int sum, vector<int> arr, int n, vector<int> &SubsetSum){
        if(ind == n){
            SubsetSum.push_back(sum);
            return;
        }
        // Pick
        SSsum(ind + 1, sum + arr[ind], arr, n, SubsetSum);
        // Not Pick
        SSsum(ind + 1, sum, arr, n, SubsetSum);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> SubsetSum;
        SSsum(0, 0, arr, n, SubsetSum);
        return SubsetSum;
    }
};
