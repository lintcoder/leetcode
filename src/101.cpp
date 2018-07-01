bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        
        return doisSymmetric(root->left, root->right);
    }
    
    bool doisSymmetric(TreeNode* ln, TreeNode* rn)
    {
        if (ln == NULL && rn == NULL)
            return true;
        else if (ln != NULL && rn != NULL)
        {
            return ln->val == rn->val && doisSymmetric(ln->left, rn->right) && doisSymmetric(ln->right, rn->left);
        }
        else
            return false;
    }