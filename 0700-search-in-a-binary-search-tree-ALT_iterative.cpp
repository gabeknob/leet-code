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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;

        stack<TreeNode*> st;
        st.push(root);

        TreeNode* cursor;

        while (st.size()) {
            cursor = st.top();
            st.pop();

            if (cursor->val == val) return cursor;

            if (cursor->left && val < cursor->val) st.push(cursor->left);
            if (cursor->right && val > cursor->val) st.push(cursor->right);
        }

        return nullptr;
    }
};
