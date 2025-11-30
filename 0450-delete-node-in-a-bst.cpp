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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else {
            if (!root->left) {
                TreeNode* substitute = root->right;
                // free(root);

                return substitute;
            }
            else if (!root->right) {
                TreeNode* substitute = root->left;
                // free(root);

                return substitute;
            }
            else {
                TreeNode* cursor = root->right;
                while (cursor->left) cursor = cursor->left;

                cursor->left = root->left;

                TreeNode* substitute = root->right;
                // free(root);

                return substitute;
            }
        }
    }
};
