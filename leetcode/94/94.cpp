#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != nullptr)
        {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans; 
    }

    // void inorder(TreeNode* root)
    // {
    //     if(root == nullptr) return NULL;
    //     if(root->left != nullptr)
    //     {
    //         inorder(root->left);    
    //     }
    //     if(root->right != nullptr)
    //     {
    //         inorder(root->right);
    //     }
    //     ans.push_back(root->val);
    // }
};