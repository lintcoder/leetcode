TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
        	return nullptr;
        return constructSubMaxBTree(nums, 0, len - 1);
    }

    TreeNode* constructSubMaxBTree(vector<int>& nums, int p, int q)
    {
        if (p > q)
            return nullptr;
        if (p == q)
            return new TreeNode(nums[p]);
        int r = p;
        int maxval = nums[p];
        for (int i = p + 1; i <= q; ++i)
            if (nums[i] > maxval)
            {
                maxval = nums[i];
                r = i;
            }
        TreeNode* node = new TreeNode(maxval);
        node->left = constructSubMaxBTree(nums, p, r - 1);
        node->right = constructSubMaxBTree(nums, r + 1, q);

        return node;
    }