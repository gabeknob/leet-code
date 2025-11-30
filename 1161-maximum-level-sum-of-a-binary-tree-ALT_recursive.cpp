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
    vector<int> levelSums;

    int maxLevelSum(TreeNode* root) {
        bfs(root, 0);

        int bestLevel = 1; int maxSum = INT_MIN;

        for (int i = 0; i < levelSums.size(); i++) {
            if (levelSums[i] > maxSum) {
                maxSum = levelSums[i];
                bestLevel = i + 1;
            }
        }

        return bestLevel;
    }

    void bfs(TreeNode* root, int level) {
        if (!root) return;

        if (levelSums.size() == level) {
            levelSums.push_back(0);
        }

        levelSums[level] += root->val;

        bfs(root->left, level + 1);
        bfs(root->right, level + 1);
    }
};
