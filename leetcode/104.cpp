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

    int traverse(TreeNode* root, int depth)
    {
        if(!root->left && !root->right)
            return depth;
        int leftDepth = 0;
        int rightDepth = 0;
        if(root->left != nullptr)
            leftDepth = traverse(root->left, depth+1);
        if(root->right != nullptr)
            rightDepth = traverse(root->right, depth+1);

        return max(leftDepth, rightDepth);
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return traverse(root,1);
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};