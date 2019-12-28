int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr || L > R)
            return 0;
        vector<int> value;
        midTravel(root, value);
        auto p = lower_bound(value.begin(), value.end(), L);
        if (p == value.end())
            return 0;
        
        int sum = 0;
        auto q = upper_bound(value.begin(), value.end(), R);
        for (auto iter = p; iter != q; ++iter)
            sum += *iter;
        
        return sum;
    }
    
    void midTravel(TreeNode* node, vector<int>& value)
    {
        if (node != nullptr)
        {
            midTravel(node->left, value);
            value.push_back(node->val);
            midTravel(node->right, value);
        }
    }