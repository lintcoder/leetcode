TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == nullptr)
        		return nullptr;
        int val = root->val;
        if (val < L)
            return trimBST(root->right, L, R);
        else if (val == L)
        {
            root->left = nullptr;
            root->right = trimBST(root->right, L, R);
            return root;
        }
        else if (val < R)
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
        else if (val == R)
        {
            root->right = nullptr;
            root->left = trimBST(root->left, L, R);
            return root;
        }
        else
        {
            return trimBST(root->left, L, R);
        }
    }