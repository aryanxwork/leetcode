/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!curr) ans.append("# ");
            else{
                ans.append(to_string(curr->val)+' ');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        ss >> str; // travel to the root
        TreeNode* root=new TreeNode(stoi(str)); //create root
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            ss >> str; //travel to next node (left)
            if(str == "#"){
                curr->left=NULL;
            }
            else{
                curr->left=new TreeNode(stoi(str));
                q.push(curr->left);
            }
            ss >> str; //move to next (right)
            if(str == "#"){
                curr->right=NULL;
            }
            else{
                curr->right=new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));