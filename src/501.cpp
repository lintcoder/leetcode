vector<int> findMode(TreeNode* root) {
        if (root == nullptr)
            return {};
        if (root->left == nullptr && root->right == nullptr)
            return {root->val};
        
        map<int, int> mp;
        mp[root->val] = 1;
        if (root->left != nullptr)
            search(root->left, mp);
        if (root->right != nullptr)
            search(root->right, mp);
        int m = 0;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second > m)
                m = iter->second;
        }
        
        vector<int> res;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second == m)
                res.push_back(iter->first);
        }
        
        return res;
    }
    
    void search(TreeNode* node, map<int, int>& mp)
    {
        mp[node->val]++;
        if (node->left != nullptr)
            search(node->left, mp);
        if (node->right != nullptr)
            search(node->right, mp);        
    }