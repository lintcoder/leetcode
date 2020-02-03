vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        int len = 1;
        
        vector<int> res;
        while (len > 0)
        {
            for (int i = 0; i < len; ++i)
            {
                TreeNode* node = dq[i];
                if (node->left != nullptr)
                    dq.push_back(node->left);
                if (node->right != nullptr)
                    dq.push_back(node->right);
            }
            res.push_back(dq[len-1]->val);
            dq.erase(dq.begin(), dq.begin()+len);
            len = dq.size();
        }
        
        return res;
    }