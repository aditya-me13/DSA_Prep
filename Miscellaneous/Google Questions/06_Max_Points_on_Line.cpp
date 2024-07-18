// Problem Link: https://www.naukri.com/code360/problems/maximum-points-on-straight-line_1092972?topList=top-google-coding-interview-questions&leftPanelTab=1&leftPanelTabValue=PROBLEM

//#include<bits/stdc++.h>
int maxPointsOnLine(vector<vector<int>> &points, int n) {
        int max_points = 0;

        for(int i=0; i<n; i++){
            unordered_map<double, int> mp;
            int parallel = 1; int coincide = 1;
            for(int j=i+1; j<n; j++){
				if(points[i][0]==points[j][0] && points[i][1]==points[j][1]){
					coincide++;
				}
                else if(points[i][0]==points[j][0])
                    parallel++;
                else{
                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    mp[slope]++;
                }
            }

            int points_count = 0;
            for(auto it : mp)
                points_count = max(points_count, it.second);

            max_points = max(parallel+coincide-1, max(points_count+coincide, max_points));
        }

        return max_points;
}