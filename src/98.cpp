bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        list<TreeNode*> lst;
        midtravel(root, lst);
        auto lim = lst.end();
        --lim;
        for (auto iter = lst.begin(); iter != lim; ++iter)
        {
            auto tmp = iter;
            tmp++;
            if ((*iter)->val >= (*tmp)->val)
                return false;
        }
        
        return true;
    }
    
    void midtravel(TreeNode* node, list<TreeNode*>& lst)
    {
        if (node != NULL)
        {
            midtravel(node->left, lst);
            lst.push_back(node);
            midtravel(node->right, lst);
        }
    }
