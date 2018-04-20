vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> dq;

        if (root == nullptr)
            return res;

        res.push_back(root->val);
        if (root->left != nullptr)
            dq.push_back(root->left);
        if (root->right != nullptr)
            dq.push_back(root->right);
        int len = 0;
        while ((len = dq.size()) != 0)
        {
            TreeNode* node = dq[0];
            int maxval = node->val;
            if (node->left != nullptr)
                dq.push_back(node->left);
            if (node->right != nullptr)
                dq.push_back(node->right);
            for (int i = 1; i < len; ++i)
            {
                node = dq[i];
                if (node->val > maxval)
                    maxval = node->val;
                if (node->left != nullptr)
                    dq.push_back(node->left);
                if (node->right != nullptr)
                    dq.push_back(node->right);
            }
            dq.erase(dq.begin(), dq.begin() + len);
            res.push_back(maxval);
        }

        return res;
    }