TreeNode* searchBST(TreeNode* root, int val) {
     if (root == nullptr)
     return root;

     TreeNode* node = root;
     while (node != nullptr)
     {
     	if (node->val == val)
     		return node;
     	else if (node->val < val)
     		node = node->right;
     	else
     		node = node->left;
     }

     return nullptr;
    }