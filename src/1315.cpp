int sumEvenGrandparent(TreeNode* root) {
        return search(root);
    }
    
    int search(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        else if (node->val % 2 == 1)
            return search(node->left) + search(node->right);
        else
        {
            int sum = 0;
            TreeNode* l1 = node->left;
            TreeNode* l2 = node->right;
            if (l1 != nullptr)
            {
                TreeNode* ll1 = l1->left;
                TreeNode* ll2 = l1->right;
                if (ll1 != nullptr)
                    sum += ll1->val;
                if (ll2 != nullptr)
                    sum += ll2->val;
            }
            if (l2 != nullptr)
            {
                TreeNode* lr1 = l2->left;
                TreeNode* lr2 = l2->right;
                if (lr1 != nullptr)
                    sum += lr1->val;
                if (lr2 != nullptr)
                    sum += lr2->val;
            }
            
            return sum + search(l1) + search(l2);
        }
    }