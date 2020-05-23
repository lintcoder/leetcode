int goodNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ct = 1;
        int maxmum = root->val;
        
        if (root->left != nullptr)
            search(root->left, maxmum, ct);
        if (root->right != nullptr)
            search(root->right, maxmum, ct);
        
        return ct;
    }
    
    void search(TreeNode* node, int maxmum, int& ct)
    {
        if (node->val >= maxmum)
        {
            ++ct;
            maxmum = node->val;
        }
        if (node->left != nullptr)
            search(node->left, maxmum, ct);
        if (node->right != nullptr)
            search(node->right, maxmum, ct);
    }