int maxDepth(TreeNode* root) {
    if (root == 0)
        return 0;
    int leftdepth = maxDepth(root->left);
    int rightdepth = maxDepth(root->right);

    return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}
