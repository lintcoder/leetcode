int findTilt(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
            return abs(subSum(root->left) - subSum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }

    
    int subSum(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        return node->val + subSum(node->left) + subSum(node->right);
    }