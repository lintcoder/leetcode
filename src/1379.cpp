TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<int> paths;
        search(original, target, paths);

        int len = paths.size();
        TreeNode* node = cloned;
        for (int i = 0; i < len; ++i)
        {
            if (paths[i] == 0)
                node = node->left;
            else
                node = node->right;
        }
        
        return node;
    }
    
    bool search(TreeNode* ori, TreeNode* target, vector<int>& paths)
    {
        if (ori != target)
        {
            if (ori->left == nullptr && ori->right == nullptr)
                return false;
            bool flag = false;
            vector<int> tmp(paths);
            if (ori->left != nullptr)
            {
                tmp.push_back(0);
                flag = search(ori->left, target, tmp);
            }
            
            if (!flag && ori->right != nullptr)
            {
                tmp.swap(paths);
                tmp.push_back(1);
                flag = search(ori->right, target, tmp);
                if (flag)
                    paths.swap(tmp);
                return flag;
            }
            else
            {
                if (flag)
                    paths.swap(tmp);
                return flag;
            }
        }
        else
            return true;
    }