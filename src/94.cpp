vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      if (root == nullptr)
      	return res;

      deque<TreeNode*> dq;
      deque<bool> flag;
      dq.push_back(root);
      flag.push_back(false);

      while (!dq.empty())
      {
      	TreeNode* node = dq.back();
      	if (flag.back() == false && node->left != nullptr)
        {
            dq.push_back(node->left);
            flag.back() = true;
            flag.push_back(false);
        }
      	else
      	{
      		res.push_back(node->val);
      		dq.pop_back();
            flag.pop_back();
      		if (node->right != nullptr)
            {
                dq.push_back(node->right);
                flag.push_back(false);
            }
      	}
      }

      return res;  
    }