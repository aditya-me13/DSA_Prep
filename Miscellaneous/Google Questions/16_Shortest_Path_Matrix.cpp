// Problem Link: https://www.naukri.com/code360/problems/shortest-path-in-a-binary-matrix_699835?topList=top-google-coding-interview-questions&leftPanelTab=0&leftPanelTabValue=PROBLEM

// #include <bits/stdc++.h> 
#define PII pair<pair<int, int>, int>

int findShortestPath(vector<vector<bool>>& mat, 
                        int sourceX, int sourceY,  
                        int destX, int destY,  
                        int n, int m)
{
    if (sourceX == destX && sourceY == destY) return 0; 
    if(!mat[destX][destY]) return -1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<PII> q;


    PII top;
    int row, col, steps, r, c;
    vector<int> nr = {0, -1, 0, +1};
    vector<int> nc = {+1, 0, -1, 0};
    q.push({{sourceX, sourceY}, 1});
    visited[sourceX][sourceY] = true; 

    while(!q.empty()){
        top = q.front();
        q.pop();
        row = top.first.first;
        col = top.first.second;
        steps = top.second;

        for(int i=0; i<4; i++){
            r = row + nr[i];
            c = col + nc[i];
            if(r==destX and c==destY){
                return steps + 1;
            } 
            else if(r<n && r>=0 && c<m && c>=0 && mat[r][c] && !visited[r][c]){
                visited[r][c]=true;
                q.push({{r, c}, steps + 1});
            }
        }
    }
    return -1;
}