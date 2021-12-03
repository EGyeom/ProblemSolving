class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root->val == key)
        {
            if(!root->right)
            {
                return root->left;
            }
            else
            {
                TreeNode * n = root->right;
                while(n->left)
                {
                    n = n->left;
                }
                swap(n->val,root->val);
                root->right = deleteNode(root->right, key);
                return root;
            }
        }
        
        if(root->val < key)
        {
            root = deleteNode(root->right,key); 
        }      
        if(root->val > key)
        {
            root = deleteNode(root->left,key);
        }

        return root;
    }
};
