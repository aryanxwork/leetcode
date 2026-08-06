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
    bool getPath(TreeNode* root, vector<TreeNode*>& path, int target) {
        if (!root) return false;

        path.push_back(root);

        if (root->val == target)
            return true;

        if (getPath(root->left, path, target) ||
            getPath(root->right, path, target))
            return true;

        path.pop_back();
        return false;
    }

    vector<TreeNode*> rootToNode(TreeNode* root, int target) {
        vector<TreeNode*> path;
        getPath(root, path, target);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> path1 = rootToNode(root, p->val);
        vector<TreeNode*> path2 = rootToNode(root, q->val);

        int i = 0;
        TreeNode* ans = nullptr;

        while (i < path1.size() && i < path2.size()) {
            if (path1[i]->val != path2[i]->val)
                break;

            ans = path1[i];
            i++;
        }

        return ans;
    }
};