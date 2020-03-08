int deepestLeavesSum(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        int len = 1;
        int sum = 0;
        while (len != 0)
        {
            int subsum = 0;
            for (int i = 0; i < len; ++i)
            {
                TreeNode* node = dq[i];
                subsum += node->val;
                if (node->left != nullptr)
                    dq.push_back(node->left);
                if (node->right != nullptr)
                    dq.push_back(node->right);
            }
            sum = subsum;
            dq.erase(dq.begin(), dq.begin()+len);
            len = dq.size();
        }
        
        return sum;
    }