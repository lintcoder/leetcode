vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
        	return res;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while (!dq.empty())
        {
        	TreeNode* node = dq.back();
        	dq.pop_back();
        	res.push_back(node->val);
        	if (node->right != nullptr)
        		dq.push_back(node->right);
        	if (node->left != nullptr)
        		dq.push_back(node->left);
        }

        return res;
    }