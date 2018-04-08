int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr)
            return -1;
        int val = root->val;
        if (root->left == nullptr)
            return -1;
        else
        {
            int min1 = root->left->val;
            int min2 = root->right->val;
            if (min1 == val && min2 != val)
            {
                min1 = findSecondMinimumValue(root->left);
                if (min1 == -1)
                    return min2;
                else
                    return min1 < min2 ? min1 : min2;
            }
            else if (min1 != val && min2 == val)
            {
                min2 = findSecondMinimumValue(root->right);
                if (min2 == -1)
                    return min1;
                else
                    return min1 < min2 ? min1 : min2;
            }
            else if (min1 != val && min2 != val)
                return min1 < min2 ? min1 : min2;
            else
            {
                min1 = findSecondMinimumValue(root->left);
                min2 = findSecondMinimumValue(root->right);
                
                if (min1 == -1 && min2 == -1)
                    return -1;
                else if (min1 == -1 && min2 != -1)
                    return min2;
                else if (min1 != -1 && min2 == -1)
                    return min1;
                else
                    return min1 < min2 ? min1 : min2;
            }
        }
    }