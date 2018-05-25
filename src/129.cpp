int sumNumbers(TreeNode* root) {
        if (root == nullptr)
        	return 0;
        int sum = 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        if (root->left != nullptr)
        	subsumNumbers(root->left, root->val, sum);
        if (root->right != nullptr)
        	subsumNumbers(root->right, root->val, sum);
        return sum;
    }

    void subsumNumbers(TreeNode* node, int sum, int& total)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            total += sum*10 + node->val;
            return;
        }
        if (node->left != nullptr)
            subsumNumbers(node->left, sum*10 + node->val, total);
        if (node->right != nullptr)
            subsumNumbers(node->right, sum*10 + node->val, total);
    }