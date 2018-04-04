TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)
        	return nullptr;
        deque<int> dq;
        if (root->left != nullptr)
        	getBSTValue(root->left, dq);
        dq.push_back(root->val);
        if (root->right != nullptr)
        	getBSTValue(root->right, dq);

        int len = dq.size();
        int sum = dq[len - 1];
        for (int i = len - 2; i >= 0; --i)
        {
        		int val = dq[i];
        		dq[i] += sum;
        		sum += val;
        }

        int count = 0;
        if (root->left != nullptr)
        	setBSTValue(root->left, dq, count);
        root->val = dq[count++];
        if (root->right != nullptr)
        	setBSTValue(root->right, dq, count);

        return root;
    }

    void getBSTValue(TreeNode* node, deque<int>& dq)
    {
        if (node->left != nullptr)
            getBSTValue(node->left, dq);
        dq.push_back(node->val);
        if (node->right != nullptr)
            getBSTValue(node->right, dq);
    }

    void setBSTValue(TreeNode* node, deque<int>& dq, int& count)
    {
        if (node->left != nullptr)
            setBSTValue(node->left, dq, count);
        node->val = dq[count++];
        if (node->right != nullptr)
            setBSTValue(node->right, dq, count);
    }