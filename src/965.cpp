bool isUnivalTree(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isUnivalSubTree(root->left, root->val) && isUnivalSubTree(root->right, root->val);
    }
    
    bool isUnivalSubTree(TreeNode* node, int key)
    {
        if (node == nullptr)
            return true;
        if (node->val != key)
            return false;
        return isUnivalSubTree(node->left, key) && isUnivalSubTree(node->right, key);
    }