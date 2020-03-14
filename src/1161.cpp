int maxLevelSum(TreeNode* root) {
        if (root == nullptr)
            return 1;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        int len = 1;
        int maxval = root->val;
        int level = 1;
        int ct = 0;
        while (len != 0)
        {
            ++ct;
            int sum = 0;
            for (int i = 0; i < len; ++i)
            {
                TreeNode* node = dq[i];
                sum += node->val;
                if (node->left != nullptr)
                    dq.push_back(node->left);
                if (node->right != nullptr)
                    dq.push_back(node->right);
            }
            
            if (sum > maxval)
            {
                maxval = sum;
                level = ct;
            }
            dq.erase(dq.begin(), dq.begin()+len);
            len = dq.size();
        }
        
        return level;
    }