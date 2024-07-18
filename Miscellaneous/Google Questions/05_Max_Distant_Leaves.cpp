// Problem Link: https://www.naukri.com/code360/problems/largest-distance-between-two-nodes-in-a-tree_1093218?topList=top-google-coding-interview-questions&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Function to perform DFS and return the farthest node and the distance to it
pair<int, int> dfs(int node, int parent, vector<vector<int>> &adj, int distance) {
    pair<int, int> farthest = {node, distance}; // (farthest node, max distance)

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            pair<int, int> candidate = dfs(neighbor, node, adj, distance + 1);
            if (candidate.second > farthest.second) {
                farthest = candidate;
            }
        }
    }

    return farthest;
}

int largestDistance(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    for (vector<int> edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Perform DFS from an arbitrary node (node 0) to find the farthest node
    pair<int, int> firstDFS = dfs(0, -1, adj, 0);

    // Perform DFS from this farthest node to find the maximum distance
    pair<int, int> secondDFS = dfs(firstDFS.first, -1, adj, 0);

    return secondDFS.second;
}