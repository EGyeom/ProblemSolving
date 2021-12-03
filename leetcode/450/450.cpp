/* 450. Delete Node in a BST
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted. */
#include <iostream>
#include <queue>
#include <cstdio>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        printNode(root);
        if(root->val < key)
        {
            root->right = deleteNode(root->right,key); 
        }      
        else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }
        else
        {
            if(root->left == nullptr)
            {
                return root->right;
            }
            else if(root->right == nullptr)
            {
                return root->left;
            }

            TreeNode * find_min = root->right;
            while(find_min->left != nullptr)
            {
                find_min = find_min->left;
            }
            root->val = find_min->val;
            root->right = deleteNode(root->right,key);
            return root;
        }
    }

    void printNode(TreeNode* root)
    {
        std::queue<TreeNode*> _queue;
        _queue.push(root);
        while(!_queue.empty())
        {
            TreeNode * node = _queue.front();
            if(node != nullptr)
            {
                printf("%d ", node->val);
                _queue.push(node->left);    
                _queue.push(node->right);
            }
            _queue.pop();
        }
        printf("\n");
    }
};


int main()
{
    Solution s;
    TreeNode * root = new TreeNode(5,new TreeNode(3,new TreeNode(2), new TreeNode(4)),new TreeNode(6,nullptr,new TreeNode(7)));
    TreeNode * ans = s.deleteNode(root,3);
    s.printNode(ans);

}