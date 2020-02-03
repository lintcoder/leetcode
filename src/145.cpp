vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
        	 return res;

        deque<TreeNode*> dq;
        deque<int> flag;

        dq.push_back(root);
        flag.push_back(0);

        while (!dq.empty())
        {
            TreeNode* node = dq.back();
            int status = flag.back();
            if (status == 0)
            {
                if (node->left != nullptr)
                {
                    flag.back() = 1;
                    dq.push_back(node->left);
                    flag.push_back(0);
                }
                else if (node->right != nullptr)
                {
                    flag.back() = 2;
                    dq.push_back(node->right);
                    flag.push_back(0);
                }
                else
                {
                    res.push_back(node->val);
                    dq.pop_back();
                    flag.pop_back();
                }
            }
            else if (status == 1)
            {
                if (node->right != nullptr)
                {
                    flag.back() = 2;
                    dq.push_back(node->right);
                    flag.push_back(0);
                }
                else
                {
                    res.push_back(node->val);
                    dq.pop_back();
                    flag.pop_back();
                }
            }
            else
            {
                res.push_back(node->val);
                dq.pop_back();
                flag.pop_back();
            }
        }
        
        return res;
    }