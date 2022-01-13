#include <bits/stdc++.h>

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
        {
            root = new TreeNode(val);
        }
        else if(root->val < val)
        {
            if(root->right == nullptr)
            {
                root->right = new TreeNode(val);
            }
            else insertIntoBST(root->right,val);
        }
        else if(root->val > val)
        {
            if(root->left == nullptr)
            {
                root->left = new TreeNode(val);
            }
            else insertIntoBST(root->left, val);
        }
        return root;
    }
};

int main()
{

}