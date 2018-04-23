TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1 || root == nullptr)
        {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        else
        {
            deque<TreeNode*> dq;
            dq.push_back(root);
            int i = 1, j = 0;
            int len = 0;
            while (i < d - 1)
            {
                len = dq.size();
                j = 0;
                while (j < len)
                {
                    TreeNode* node = dq[j++];
                    if (node->left != nullptr)
                        dq.push_back(node->left);
                    if (node->right != nullptr)
                        dq.push_back(node->right);
                }
                dq.erase(dq.begin(), dq.begin() + len);
                ++i;
            }
            len = dq.size();
            j = 0;
            while (j < len)
            {
                TreeNode* node = dq[j];
                TreeNode* lnode = new TreeNode(v);
                lnode->left = dq[j]->left;
                dq[j]->left = lnode;
                TreeNode* rnode = new TreeNode(v);
                rnode->right = dq[j]->right;
                dq[j]->right = rnode;
                ++j;
            }
            return root;
        }
    }