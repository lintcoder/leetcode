vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> vec;
        struct Elem
        {
            TreeNode* node;
            bool status;
            Elem(TreeNode* tn = nullptr, bool flag = false):node(tn), status(flag){}
        };
        
        deque<Elem> dq;
        dq.push_back(Elem(root, true));
        
        int index = 0, len = 1;
        bool flag = true;
        while (flag)
        {
            flag = false;
            int lim = len;
            for (int i = index; i < lim; ++i)
            {
                TreeNode* tmp = dq[i].node;
                if (tmp->left != nullptr)
                {
                    flag = true;
                    dq.push_back(Elem(tmp->left, true));
                    len++;
                }
                if (tmp->right != nullptr)
                {
                    flag = true;
                    dq.push_back(Elem(tmp->right, true));
                    len++;
                }
            }
            index = lim;
        }
        
        int len1 = dq.size();
        int len2 = to_delete.size();
        map<TreeNode*, TreeNode*> mp;
        mp.insert(make_pair(root, nullptr));
        for (int i = 0; i < len1; ++i)
        {
            TreeNode* node = dq[i].node;
            if (node->left != nullptr)
                mp[node->left] = node;
            if (node->right != nullptr)
                mp[node->right] = node;
        }
        
        for (int i = 0; i < len2; ++i)
        {
            for (int j = 0; j < len1; ++j)
            {
                if (dq[j].node->val == to_delete[i])
                {
                    dq[j].status = false;
                    if (dq[j].node->left != nullptr)
                        mp[dq[j].node->left] = nullptr;
                    if (dq[j].node->right != nullptr)
                        mp[dq[j].node->right] = nullptr;
                }
                else if (dq[j].node->left != nullptr && dq[j].node->left->val == to_delete[i])
                    dq[j].node->left = nullptr;
                else if (dq[j].node->right != nullptr && dq[j].node->right->val == to_delete[i])
                    dq[j].node->right = nullptr;
            }
        }
        
        for (int i = 0; i < len1; ++i)
        {
            if (dq[i].status && mp[dq[i].node] == nullptr)
            {
                vec.push_back(dq[i].node);
            }
        }
        
        return vec;
    }