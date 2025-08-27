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

    void bt(TreeNode* root, vector<string>& v, string temp)
    {
        temp += to_string(root->val);

        if(root->left)
        {
            bt(root->left, v, temp + "->");
        }
        if(root->right)
        {
            bt(root->right, v, temp + "->");
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            v.push_back(temp);
        }

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        bt(root, answer, "");
        return answer;
    }
};
