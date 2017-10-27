bool findTarget(TreeNode* root, int k) {
        if (root == nullptr)
        	return false;
        vector<int> elem;
        if (root->left != nullptr)
        	getBSTValue(root->left, elem);
        elem.push_back(root->val);
        if (root->right != nullptr)
        	getBSTValue(root->right, elem);

        int len = elem.size();
        for (int i = 0; i < len; ++i)
        {
            if (elem[i] >= k - elem[i])
                break;
            if (binary_search(elem.begin() + i + 1, elem.end(), k - elem[i]))
                return true;
        }
        return false;
    }

    void getBSTValue(TreeNode* node, vector<int>& vec)
    {
        if (node->left != nullptr)
            getBSTValue(node->left, vec);
        vec.push_back(node->val);
        if (node->right != nullptr)
            getBSTValue(node->right, vec);
    }