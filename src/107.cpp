vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        else
        {
            TreeNode* node = root;
            deque<TreeNode*> dq;
            dq.push_back(node);
            while (!dq.empty())
            {
                int len = dq.size();
                vector<int> vec;
                for (int i = 0; i < len; ++i)
                {
                    TreeNode* t = dq.front();
                    vec.push_back(t->val);
                    if (t->left != NULL)
                        dq.push_back(t->left);
                    if (t->right != NULL)
                        dq.push_back(t->right);
                    dq.pop_front();
                }

                res.push_back(vec);
            }
            reverse(res.begin(), res.end());
            return res;
        }
    }