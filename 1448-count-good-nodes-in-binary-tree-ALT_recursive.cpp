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
    int goodNodes(TreeNode* root) {
        return goodNodesDfs(root, INT_MIN);
    }

    int goodNodesDfs(TreeNode* root, int maxValue) {
        if (!root) return 0;

        bool isGoodNode = root->val >= maxValue;
        maxValue = max(maxValue, root->val);

        return isGoodNode + goodNodesDfs(root->left, maxValue) + goodNodesDfs(root->right, maxValue);
    }
};
