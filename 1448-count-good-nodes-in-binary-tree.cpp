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
        stack<pair<TreeNode*,int>> st;
        st.push({root, root->val});
        int goodNodes = 0;

        TreeNode* cursor;

        while (st.size()) {
            auto [cursor, maxParent] = st.top();
            st.pop();

            if (cursor->val >= maxParent) goodNodes++;
            maxParent = max(maxParent, cursor->val);

            if (cursor->left) st.push({cursor->left,maxParent});
            if (cursor->right) st.push({cursor->right,maxParent});
        }

        return goodNodes;
    }
};
