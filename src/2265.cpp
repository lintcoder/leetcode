int averageOfSubtree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int ct = 0;
        int n = 0;
        search(root, n, ct);
        
        return ct;
    }
    
    int search(TreeNode* node, int& n, int& ct)
    {
        int sum = node->val;
        int p = 0, q = 0;
        if(node->left != nullptr)
            sum += search(node->left, p, ct);
        if(node->right != nullptr)
            sum += search(node->right, q, ct);
        
        if(sum/(p+q+1) == node->val)
            ++ct;
        n = p+q+1;
        return sum;     
    }