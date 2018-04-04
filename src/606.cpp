string tree2str(TreeNode* t) {
        if (t == nullptr)
        	return string();
        string res(to_string(t->val));

        if (t->left != nullptr)
        	res += transfersubtree(t->left);
        if (t->right != nullptr)
        {
            if (t->left == nullptr)
                res += "()" + transfersubtree(t->right);
            else
                res += transfersubtree(t->right);
        }

        return res;
    }

    string transfersubtree(TreeNode* node)
    {
        string str = "(" + to_string(node->val);
        if (node->left != nullptr)
            str += transfersubtree(node->left);
        if (node->right != nullptr)
        {
            if (node->left == nullptr)
                str += "()" + transfersubtree(node->right);
            else
                str += transfersubtree(node->right);
        }
        str += ")";

        return str;
    }