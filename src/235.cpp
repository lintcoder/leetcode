TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q)
            return root;
        vector<TreeNode*> path;
        TreeNode* node = root;
        while (node != nullptr)
        {
            path.push_back(node);
            if (node->val > p->val)
            {
                node = node->left;
            }
            else if (node->val == p->val)
                break;
            else
            {
                node = node->right;
            }
        }

        node = root;
        int len = path.size();
        int i = 0;
        while (i < len && node == path[i])
        {
            if (node == p || node == q)
                return node;
            node = node->val > q->val ? node->left : node->right;
            ++i;
        }
        
        return path[i-1];
    }