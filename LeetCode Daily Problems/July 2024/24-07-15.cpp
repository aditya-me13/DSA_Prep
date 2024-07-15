// Problem Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, bool> root; // node val, is any incoming edged
        unordered_map<int, TreeNode*> mp;  // node val, node

        for(vector<int> description:descriptions){
            int parent = description[0];
            int child = description[1];
            int is_left = description[2]; 

            if(mp.find(child)==mp.end()) mp[child] = new TreeNode(child);
            if(mp.find(parent)==mp.end()) mp[parent] = new TreeNode(parent);

            if(is_left) mp[parent]->left = mp[child];
            else mp[parent]->right = mp[child];
            
            root[child] = true;
        }
        
        for(auto dis:descriptions){
            if(root.find(dis[0])==root.end()) return mp[dis[0]];
        }

        return nullptr;
    }
};