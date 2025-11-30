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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*,int>> st;
        st.push({ root, 1 });

        int currd = 0;
        int maxd = currd;

        while (st.size()) {
            auto [cursor, currd] = st.top();
            st.pop();

            maxd = max(maxd, currd);

            if (cursor->left) {
                st.push({ cursor->left, currd + 1 });
            }
            if (cursor->right) {
                st.push({ cursor->right, currd + 1 });
            }
        }

        return maxd;
    }
};
