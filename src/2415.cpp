TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        bool flag = true;
        
        while (!dq.empty())
        {
            int n = dq.size();
            int ct = 0;
            for (int i = 0; i < n; ++i)
            {
                TreeNode* node = dq[i];
                if (node->left != nullptr)
                {
                    dq.push_back(node->left);
                    dq.push_back(node->right);
                    ct += 2;
                }
            }
            
            if (ct > 0)
            {
                if (flag)
                {
                    int lim = ct/2;
                    for (int i = 0; i < lim; ++i)
                    {
                        int tmp = dq[n+i]->val;
                        dq[n+i]->val = dq[n+ct-1-i]->val;
                        dq[n+ct-1-i]->val = tmp;
                    }
                }
                
                flag = !flag;
                dq.erase(dq.begin(), dq.begin()+n);
            }
            else
                break;
        }
        
        return root;
    }