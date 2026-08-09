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

    int findHeightLeft(TreeNode* node) {
        int h = 0;

        while (node) {
            h++;
            node = node->left;
        }

        return h;
    }

    int findHeightRight(TreeNode* node) {
        int h = 0;

        while (node) {
            h++;
            node = node->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {

        if (root == NULL)
            return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // Perfect binary tree
        if (lh == rh)
            return (1 << lh) - 1;

        // Not perfect → recursively count
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};