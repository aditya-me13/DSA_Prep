// Problem Link : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16
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
private:
    bool path_to_node(TreeNode* root, int dest, string &route){
        if(!root) return false;

        if(root->val == dest){
            return true;
        }

        if(path_to_node(root->left, dest, route)){
            route+='L';
            return true;
        }

        else if(path_to_node(root->right, dest, route)){
            route+='R';
            return true;
        }

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path_to_start = "";
        string path_to_dest = "";

        path_to_node(root, startValue, path_to_start);
        path_to_node(root, destValue, path_to_dest);

        reverse(path_to_start.begin(), path_to_start.end());
        reverse(path_to_dest.begin(), path_to_dest.end());

        int len = min(path_to_start.size(), path_to_dest.size());
        int i = 0;
        while (i < len && path_to_start[i] == path_to_dest[i]) {
            i++;
        }

        path_to_start = path_to_start.substr(i);
        path_to_dest = path_to_dest.substr(i);

        string ans = string(path_to_start.size(), 'U') + path_to_dest;

        return ans;
    }
};