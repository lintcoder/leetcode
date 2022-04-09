int countNodes(TreeNode* root) {
        int ct = 0;
        search(root, ct);
        
        return ct;
    }
    
    void search(TreeNode* node, int& n)
    {
        if (node != nullptr)
        {
            ++n;
            search(node->left, n);
            search(node->right, n);
        }
    }