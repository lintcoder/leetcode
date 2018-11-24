bool isBalanced(TreeNode* root) {
        int depth = 0;
        return doisBalanced(root, depth);
    }
    
    bool doisBalanced(TreeNode* node, int& depth)
    {
        if (node == NULL)
            return true;
        int depth1 = depth, depth2 = depth;
        if (!doisBalanced(node->left, depth1) || !doisBalanced(node->right, depth2) || abs(depth1 - depth2) > 1)
            return false;
        depth = depth1 > depth2 ? depth1 + 1 : depth2 + 1;
        return true;
    }