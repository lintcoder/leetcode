int minDiffInBST(TreeNode* root) {
        int mindiff = INT_MAX;
        int ct = 0;
        int m = 0, n = 0;
        search(root, mindiff, m, n, ct);
        
        return mindiff;
    }
    
    void search(TreeNode* node, int& mindiff, int& m, int& n, int& ct)
    {
        if (node->left != nullptr)
            search(node->left, mindiff, m, n, ct);
        if (ct == 0)
        {
            m = node->val;
            ++ct;
        }
        else if (ct == 1)
        {
            n = node->val;
            int diff = n-m;
            if (diff < mindiff)
                mindiff = diff;
            ++ct;
        }
        else
        {
            m = n;
            n = node->val;
            int diff = n-m;
            if (diff < mindiff)
                mindiff = diff;
        }
        if (node->right != nullptr)
            search(node->right, mindiff, m, n, ct);
    }