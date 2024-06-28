class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> Pascal;
    
    if(numRows == 0) return Pascal;

    vector<int> row(1,1);
    Pascal.push_back(row);

    for(int i = 1; i < numRows; i ++){
        vector<int> row(i+1, 1);
        for(int j = 1; j < i; j++){
            row[j] = Pascal[i-1][j-1]+Pascal[i-1][j];
        }
        Pascal.push_back(row);
    }
        return Pascal;
    }
};
