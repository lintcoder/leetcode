vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root == NULL)
            return paths;
        else
        {
            string path(num2str(root->val));
            if (root->left != NULL || root->right != NULL)
            {
                if (root->left != NULL)
                    collectpath(paths, path, root->left);
                if (root->right != NULL)
                    collectpath(paths, path, root->right);
            }
            else
                paths.push_back(path);
            return paths;
        }
    }
    
    void collectpath(vector<string>& paths, const string& path, TreeNode* node)
    {
        string str(path + "->" + num2str(node->val));
        if (node->left != NULL || node->right != NULL)
        {
            string subpath(str);
            if (node->left != NULL)
                collectpath(paths, subpath, node->left);
            if (node->right != NULL)
                collectpath(paths, subpath, node->right);
        }
        else
            paths.push_back(str);
    }
    
    string num2str(int num)
    {
        if (num == 0)
            return "0";
        
        string str;
        int flag = 0;
        if (num < 0)
        {
            flag = 1;
            num = -num;
        }
        while (num > 0)
        {
            str.push_back(num % 10 + '0');
            num /= 10;
        }
        if (flag)
            str.push_back('-');
        reverse(str.begin(), str.end());
        
        return str;
    }