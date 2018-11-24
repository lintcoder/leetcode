int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        vector<int> sum_vec;
        sum_vec.push_back(root->val);
        int total = root->val == sum ? 1 : 0;
        return total + dopathSum(root->left, sum_vec, sum) + dopathSum(root->right, sum_vec, sum);
    }
    
    int dopathSum(TreeNode* node, const vector<int>& vec, int sum)
    {
        if (node == NULL)
            return 0;
        else
        {
            int total = 0;
            vector<int> sum_vec(vec);
            int len = sum_vec.size();
            for (int i = 0; i < len; ++i)
            {
                sum_vec[i] = sum_vec[i] + node->val;
                if (sum_vec[i] == sum)
                    ++total;
            }
            sum_vec.push_back(node->val);
            if (node->val == sum)
                ++total;
            return total + dopathSum(node->left, sum_vec, sum) + dopathSum(node->right, sum_vec, sum);
        }
    }