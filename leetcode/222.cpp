class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root){
            return 0;
        }

        int leaf = 0;
        if (root->left)
            leaf += countNodes(root->left);
        root->left = nullptr;
        if (root->right)
            leaf += countNodes(root->right);
        root->right = nullptr;
        return leaf + 1;
    }
};
