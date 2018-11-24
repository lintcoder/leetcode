bool isSubtree(TreeNode* s, TreeNode* t) {
        return doisSubtree(s, t, false);
    }
    
    bool doisSubtree(TreeNode* s, TreeNode* t, bool status) {
        if (s == nullptr && t == nullptr)
        	return true;
        else if (s == nullptr && t != nullptr)
        	return false;
        else if (s != nullptr && t == nullptr)
        	return false;
        else
        {
            bool flag = false;
            if (s->val == t->val)
            {
                flag = doisSubtree(s->left, t->left, true) && doisSubtree(s->right, t->right, true);
                if (flag)
                    return true;
            }
            if (status)
                return false;
            if (doisSubtree(s->left, t, false))
                return true;
            else
                return doisSubtree(s->right, t, false);
        }
    }