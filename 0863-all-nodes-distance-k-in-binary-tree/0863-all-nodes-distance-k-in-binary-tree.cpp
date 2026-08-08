/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void makeParent(TreeNode* root, TreeNode* parent,
                    unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL)
            return;

        mp[root] = parent;

        makeParent(root->left, root, mp);
        makeParent(root->right, root, mp);
    }

    void findNodes(TreeNode* root, TreeNode* prev, int k,
                   vector<int>& ans,
                   unordered_map<TreeNode*, TreeNode*>& mp) {

        if (root == NULL)
            return;

        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        // Go to left child
        if (root->left != prev)
            findNodes(root->left, root, k - 1, ans, mp);

        // Go to right child
        if (root->right != prev)
            findNodes(root->right, root, k - 1, ans, mp);

        // Go to parent
        if (mp[root] != prev)
            findNodes(mp[root], root, k - 1, ans, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> mp;

        // Store parent of every node
        makeParent(root, NULL, mp);

        vector<int> ans;

        // Start from target
        findNodes(target, NULL, k, ans, mp);

        return ans;
    }
};