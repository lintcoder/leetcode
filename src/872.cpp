bool leafSimilar(TreeNode* root1, TreeNode* root2) {
     if (root1 == nullptr && root2 == nullptr)
     return true;

     if (root1 == nullptr || root2 == nullptr)
     return false;

     vector<int> leaf1, leaf2;
     getLeaf(root1, leaf1);
     getLeaf(root2, leaf2);

     int len1 = leaf1.size();
     int len2 = leaf2.size();
     if (len1 != len2)
     return false;

     for (int i = 0; i < len1; ++i)
     {
     	if (leaf1[i] != leaf2[i])
     		return false;
     }

     return true;
    }

void getLeaf(TreeNode* node, vector<int>& vec)
{
	if (node->left == nullptr && node->right == nullptr)
		vec.push_back(node->val);
	else
	{
		if (node->left != nullptr)
			getLeaf(node->left, vec);
		if (node->right != nullptr)
			getLeaf(node->right, vec);
	}
}