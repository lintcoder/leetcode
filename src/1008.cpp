TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        if (len == 0)
            return nullptr;
        if (len == 1)
            return new TreeNode(preorder[0]);
        
        return search(preorder, 0, len-1);
    }
    
    TreeNode* search(vector<int>& vec, int p, int q)
    {
        if (p > q)
            return nullptr;
        if (p == q)
            return new TreeNode(vec[p]);
        TreeNode* node = new TreeNode(vec[p]);
        int i = 0;
        for (i = p+1; i <= q; ++i)
        {
            if (vec[i] > vec[p])
                break;
        }
        
        if (vec[p+1] < vec[p])
            node->left = search(vec, p+1, i-1);
        if (i <= q)
            node->right = search(vec, i, q);
        
        return node;
    }