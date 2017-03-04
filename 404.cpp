enum Side {LEFT, RIGHT};
int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL)
        return 0;
    return dosumOfLeftLeaves(root->left, LEFT) + dosumOfLeftLeaves(root->right, RIGHT);
}
int dosumOfLeftLeaves(TreeNode* node, enum Side side)
{
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return side == LEFT ? node->val : 0;
    else
        return dosumOfLeftLeaves(node->left, LEFT) + dosumOfLeftLeaves(node->right, RIGHT);
}
