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
    int maxZigZag;

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;

        dfs(root->left, 1, 'l');
        dfs(root->right, 1, 'r');

        return maxZigZag;
    }

    void dfs(TreeNode* root, int zlevel, char direction) {
        if (!root) return;

        maxZigZag = max(maxZigZag, zlevel);

        dfs(root->left, direction == 'r' ? zlevel + 1 : 1, 'l');
        dfs(root->right, direction == 'l' ? zlevel + 1 : 1, 'r');
    }
};
