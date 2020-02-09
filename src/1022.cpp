int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int res = 0;
        int sum = 0;
        search(root, res, sum);
        
        return sum;
    }
    
    void search(TreeNode* node, int res, int& sum)
    {
        res = res*2 + node->val;
        if (node->left != nullptr || node->right != nullptr)
        {
            if (node->left != nullptr)
                search(node->left, res, sum);
            if (node->right != nullptr)
                search(node->right, res, sum);
        }
        else
        {
            sum += res;
        }
    }