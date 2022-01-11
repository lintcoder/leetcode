TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return generate(nums, 0, len-1); 
    }
    
    TreeNode* generate(vector<int>& nums, int p, int q)
    {
        TreeNode* node = nullptr;
        if (p <= q)
        {
            int lim = (p+q)/2;
            node = new TreeNode(nums[lim]);
            node->left = generate(nums, p, lim-1);
            node->right = generate(nums, lim+1, q);
        }
        
        return node;
    }