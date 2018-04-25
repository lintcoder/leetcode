bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        return dohasPathSum(root, 0, sum);
    }
    
    bool dohasPathSum(TreeNode* node, int subsum, int sum)
    {
        int val = node->val;
        TreeNode* lnode = node->left;
        TreeNode* rnode = node->right;
        bool flag = false;
        if (lnode == NULL && rnode == NULL)
            return subsum + val == sum;
        else if (lnode != NULL)
            flag = dohasPathSum(lnode, subsum + val, sum);
        if (!flag && rnode != NULL)
            flag = dohasPathSum(rnode, subsum + val, sum);
        return flag;
    }