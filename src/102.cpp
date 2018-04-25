vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> dq[2];
        
        TreeNode* node = root;
        int i = 0;
        if (node != NULL)
        {
            dq[0].push_back(node);
        }
        while (!dq[i].empty())
        {
            vector<int> vec;
            while (!dq[i].empty())
            {
                TreeNode* t = dq[i].front();
                vec.push_back(t->val);
                if (t->left != NULL)
                    dq[1 - i].push_back(t->left);
                if (t->right != NULL)
                    dq[1 - i].push_back(t->right);
                dq[i].pop_front();
            }
            res.push_back(vec);
            i = 1 - i;
        }
        
        return res;
    }