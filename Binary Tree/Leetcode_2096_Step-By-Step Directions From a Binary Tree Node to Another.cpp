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

    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {

        //if found any of the p or q node, return that node
        if (root == NULL or root->val == p or root->val == q) {
            return root;
        }

        TreeNode* left = NULL, * right = NULL;

        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);

        if (left and right) { //already got the p and q nodes
            return root;
        }

        return left == NULL ? right : left;
    }

    bool search(TreeNode* node, int target, string& path) {

        if (node == NULL) return false;

        if (node->val == target) return true;

        bool found = false;

        path.push_back('L');
        found = search(node->left, target, path);
        if (found) return true;
        path.pop_back(); // backtracking step


        path.push_back('R');
        found = search(node->right, target, path);
        if (found) return true;
        path.pop_back(); // backtracking step

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lowestCommonAncestor(root, startValue, destValue);

        string startPath, destPath; // from LCA node

        search(lcaNode, startValue, startPath);
        search(lcaNode, destValue, destPath);

        for (auto& x : startPath) {
            x = 'U';
        }
        return startPath + destPath;
    }
};