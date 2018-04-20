int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        return dofindBottomLeftValue(root, depth);
    }
    
    int dofindBottomLeftValue(TreeNode* node, int& depth)
    {
        int ldepth = depth, rdepth = depth;
        int lval = 0, rval = 0;
        
        if (node->left == NULL && node->right == NULL)
            return node->val;
        if (node->left != NULL)
        {
            ldepth = depth + 1;
            lval = dofindBottomLeftValue(node->left, ldepth);
        }
        if (node->right != NULL)
        {
            rdepth = depth + 1;
            rval = dofindBottomLeftValue(node->right, rdepth);
        }
        
        depth = ldepth >= rdepth ? ldepth : rdepth;
        return ldepth >= rdepth ? lval : rval;
    }