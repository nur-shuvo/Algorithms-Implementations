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

    unordered_set<string> treePath;
    unordered_map<string, TreeNode*> duplicateTreeRoot;

    string encodeTree(TreeNode* root) {
        if (root == NULL) return "";

        string treePathString = "";
        treePathString += encodeTree(root->left) + 'l';
        treePathString += (to_string(root->val));
        treePathString += encodeTree(root->right) + 'r';

        if (treePath.find(treePathString) != treePath.end()) {
            duplicateTreeRoot[treePathString] = root;
        }

        treePath.insert(treePathString);

        return treePathString;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        encodeTree(root);

        vector<TreeNode*> ans;
        for (auto& entry : duplicateTreeRoot) {
            ans.emplace_back(entry.second);
        }
        return ans;
    }
};