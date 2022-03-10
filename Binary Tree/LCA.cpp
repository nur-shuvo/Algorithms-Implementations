class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //if found any of the p or q node, return that node
        if (root == p or root == q) {
            return root;
        }

        //if leaf node return null
        if (!root->left and !root->right) {
            return NULL;
        }

        TreeNode* left = NULL, * right = NULL;
        if (root->left) {
            left = lowestCommonAncestor(root->left, p, q);
        }
        if (root->right) {
            right = lowestCommonAncestor(root->right, p, q);
        }

        if (left and right) { //already got the p and q nodes
            return root;
        }

        return left == NULL ? right : left;
    }
};