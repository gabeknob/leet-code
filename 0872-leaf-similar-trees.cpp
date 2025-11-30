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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> edges1 = getEdges(root1);
        vector<int> edges2 = getEdges(root2);

        if (edges1.size() != edges2.size()) return false;

        for (int i = 0; i < edges1.size(); i++) {
            if (edges1[i] != edges2[i]) return false;
        }

        return true;
    }

    vector<int> getEdges(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;

        st.push(root);
        TreeNode* cursor;

        while(st.size()) {
            cursor = st.top();
            st.pop();

            if (cursor->left) st.push(cursor->left);
            if (cursor->right) st.push(cursor->right);

            if (!cursor->left && !cursor->right) {
                v.push_back(cursor->val);
            }
        }

        return v;
    }
};
