bool isCousins(TreeNode* root, int x, int y) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        int ct = 1;
        int n = 0;
        int p[2] = {-1,-1};
        while (ct != 0)
        {
            ct = 0;
            int len = dq.size();
            for (int i = 0; i < len; ++i)
            {
                if (dq[i] == nullptr)
                {
                    dq.push_back(nullptr);
                    dq.push_back(nullptr);
                }
                else if (dq[i]->val == x || dq[i]->val == y)
                {
                    p[n++] = i;
                }
                else
                {
                    dq.push_back(dq[i]->left);
                    dq.push_back(dq[i]->right);
                    ++ct;
                }
            }
            if (n == 1 || n == 2 || ct == 0)
                break;
            dq.erase(dq.begin(), dq.begin()+len);
        }
        
        if (n == 1)
            return false;
        if (n == 2)
            return p[0]/2 != p[1]/2;
        return false;
    }