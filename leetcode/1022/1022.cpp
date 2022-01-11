/**
 * Definition for a binary tree node.
 */
#include <bits/stdc++.h>

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int grade = -1;
    int result = 0;
    int sumRootToLeaf(TreeNode* root) {
        grade++;
        if(root->left == nullptr && root->right == nullptr)
        {
            grade--;
            return 0;
        }
        result += sumRootToLeaf(root)
        result += root->val * (1 << grade);


        grade--;

    }
};