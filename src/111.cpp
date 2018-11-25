int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        else if (root->left != NULL && root->right == NULL)
            return 1 + minDepth(root->left);
        else if (root->left == NULL && root->right != NULL)
            return 1 + minDepth(root->right);
        else
        {
            int ldepth = minDepth(root->left);
            int rdepth = minDepth(root->right);
            return ldepth < rdepth ? ldepth + 1 : rdepth + 1;
        }
    }