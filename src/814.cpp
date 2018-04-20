TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr)
        	return root;

        bool flag1 = false, flag2 = false;
        if (root->left != nullptr)
        {
        	flag1 = dopruneTree(root->left);
        	if (flag1)
        		root->left = nullptr;
        }
        if (root->right != nullptr)
        {
        	flag2 = dopruneTree(root->right);
        	if (flag2)
        		root->right = nullptr;
        }
        if (flag1 && flag2 && root->val == 0)
        {
        	delete root;
        }
        return root;
    }

    bool dopruneTree(TreeNode* node)
    {
        bool flag1 = false, flag2 = false;
        if (node->left != nullptr)
            flag1 = dopruneTree(node->left);
        else
            flag1 = true;
        if (node->right != nullptr)
            flag2 = dopruneTree(node->right);
        else
            flag2 = true;
        if (flag1)
            node->left = nullptr;
        if (flag2)
            node->right = nullptr;
        if (flag1 && flag2 && node->val == 0)
        {
            delete node;
            return true;
        }
        else
            return false;
    }