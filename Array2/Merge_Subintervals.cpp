class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());   
        int n = intervals.size();
        vector<vector<int>> A;
        int j = 0;
        A.push_back(intervals[0]);

        for (int i = 1; i < n; i++){
            if(A[j][1] < intervals[i][0] ){
                A.push_back(intervals[i]);
                j++;
            }
            else{
                A[j][1] = max(A[j][1], intervals[i][1]);
            }

        }

    return A;
    }
};
