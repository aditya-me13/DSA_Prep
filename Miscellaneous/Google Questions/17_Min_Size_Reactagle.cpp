// Problem Link: https://www.naukri.com/code360/problems/triplet-sum-zero_893177?topList=top-google-coding-interview-questions&leftPanelTab=1&leftPanelTabValue=PROBLEM

// #include<bits/stdc++.h>
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left_smaller(n);
        vector<int> right_smaller(n);

        stack<int> st;

        // Calculate left_smaller array
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left_smaller[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // Calculate right_smaller array
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right_smaller[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        // Calculate the maximum area
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int width = right_smaller[i] - left_smaller[i] - 1;
            maxi = max(maxi, width * heights[i]);
        }

        return maxi;
    }

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	vector<int> currRow = mat[0];
	int maxi = largestRectangleArea(currRow);

	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] != 0) currRow[j]++;
			else currRow[j] = 0;
		}
		maxi = max(maxi, largestRectangleArea(currRow));
	}
	return maxi;
}
