TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr)
            return nullptr;
        
        vector<stack<TreeNode*>> vec;
        stack<TreeNode*> stk;
        
        search(root, target, stk, vec);
        int len = vec.size();
        for (int i = 0; i < len; ++i)
        {
            TreeNode* node = vec[i].top();
            vec[i].pop();
            while (!vec[i].empty())
            {
                TreeNode* par = vec[i].top();
                if (par->left == node)
                    par->left = nullptr;
                else
                    par->right = nullptr;
                delete node;
                if (par->val == target && par->left == nullptr && par->right == nullptr)
                {
                    node = par;
                    vec[i].pop();
                }
                else
                    break;
            }
            if (vec[i].empty())
                return nullptr;
        }
        
        return root;
    }
    
    void search(TreeNode* node, int target, stack<TreeNode*> stk, vector<stack<TreeNode*>>& vec)
    {
        stk.push(node);
        if (node->val == target && node->left == nullptr && node->right == nullptr)
        {
            vec.push_back(stk);
        }
        else
        {
            if (node->left != nullptr)
                search(node->left, target, stk, vec);
            if (node->right != nullptr)
                search(node->right, target, stk, vec);
        }
    }