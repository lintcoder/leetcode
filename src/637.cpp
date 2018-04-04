vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr)
            return res;
        deque<TreeNode*> dq;
        dq.push_back(root);

        int sz = 0;
        while ((sz = dq.size()) != 0)
        {
            double sum = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* node = dq[i];
                sum += node->val;
                if (node->left != nullptr)
                    dq.push_back(node->left);
                if (node->right != nullptr)
                    dq.push_back(node->right);
            }

            dq.erase(dq.begin(), dq.begin() + sz);
            sum /= sz;
            res.push_back(sum);
        }

        return res;
    }