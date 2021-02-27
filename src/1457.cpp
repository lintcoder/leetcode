int pseudoPalindromicPaths (TreeNode* root) {
        int arr[10] = {0};
        int ct = 0;
        
        search(root, arr, ct);
        
        return ct;
    }
    
    void search(TreeNode* node, int* arr, int& ct)
    {
        int v = node->val;
        arr[v]++;
        if (node->left == nullptr && node->right == nullptr)
        {
            int n = 0;
            for (int i = 1; i < 10; ++i)
            {
                if (arr[i]%2 == 1)
                {
                    ++n;
                    if (n == 2)
                        break;
                }
            }
            if (n < 2)
                ++ct;
            
            return;
        }
        if (node->left != nullptr)
        {
            search(node->left, arr, ct);
            arr[node->left->val]--;
        }
        if (node->right != nullptr)
        {
            search(node->right, arr, ct);
            arr[node->right->val]--;
        }
    }