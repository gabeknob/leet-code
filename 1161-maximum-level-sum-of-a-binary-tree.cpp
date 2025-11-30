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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*,int>> q;
        map<int,int> depthSum;
        q.push({root, 1});

        int maxSum = INT_MIN;
        int bestLevel = 1;

        TreeNode* cursor;

        while(q.size()) {
            auto [cursor, currDepth] = q.front();
            q.pop();

            if (depthSum.count(currDepth)) {
                depthSum[currDepth] += cursor->val;
            } else {
                depthSum[currDepth] = cursor->val;
            }

            if (cursor->left) q.push({cursor->left, currDepth + 1});
            if (cursor->right) q.push({cursor->right, currDepth + 1});
        }

        for (auto level : depthSum) {
            if (level.second > maxSum) {
                maxSum = level.second;
                bestLevel = level.first;
            }
        }

        return bestLevel;
    }
};
