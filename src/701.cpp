TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        else if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }