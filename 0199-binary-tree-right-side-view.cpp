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
    vector<int> rside;
    int currMaxLevel = 0;

    vector<int> rightSideView(TreeNode* root) {
        bfs(root, 1);

        return rside;
    }

    void bfs(TreeNode* root, int level) {
        if (!root) return;

        if (level > currMaxLevel) {
            rside.push_back(root->val);
            currMaxLevel = level;
        }

        bfs(root->right, level + 1);
        bfs(root->left, level + 1);
    }
};
