int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        add2vec(vec, root);
        sort(vec.begin(), vec.end());
        
        int len = vec.size();
        int min_diff = abs(vec[1] - vec[0]);
        for (int i = 2; i < len; ++i)
        {
            int diff = abs(vec[i] - vec[i - 1]);
            if (diff < min_diff)
                min_diff = diff;
        }
        
        return min_diff;
    }
    
    void add2vec(vector<int>& vec, TreeNode* root)
    {
        if (root == NULL)
            return;
        vec.push_back(root->val);
        add2vec(vec, root->left);
        add2vec(vec, root->right);
    }