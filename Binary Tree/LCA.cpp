class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //if found any of the p or q node, return that node
        if (root == NULL or root == p or root == q) {
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
};
