vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        if (root == nullptr)
            return res;
        struct Elem
        {
        	int val;
        	int pos;
        	Elem(int v, int p): val(v), pos(p){}
        };

        vector<vector<Elem>> levelvec;
        deque<TreeNode*> dq;
        levelvec.push_back(vector<Elem>(1, Elem(root->val, 0)));
        dq.push_back(root);
        int sz = 0;
        int layer = 0;
        while ((sz = dq.size()) != 0)
        {
        	vector<Elem> vec;
        	for (int i = 0; i != sz; ++i)
        	{
        		TreeNode* node = dq[i];
        		if (node->left != nullptr)
        		{
        			dq.push_back(node->left);
        			vec.push_back(Elem(node->left->val, levelvec[layer][i].pos * 2));
        		}
        		if (node->right != nullptr)
        		{
        			dq.push_back(node->right);
        			vec.push_back(Elem(node->right->val, levelvec[layer][i].pos * 2 + 1));
        		}
        	}
        	dq.erase(dq.begin(), dq.begin() + sz);
        	levelvec.push_back(vec);
        	layer++;
        }
        
        int num = pow(2, layer) - 1;
        for (int i = 0; i < layer; ++i)
        	res.push_back(vector<string>(num, string("")));
        
        for (int i = 0; i < layer; ++i)
        {
        	int len = levelvec[i].size();
            int r = pow(2, layer - i);
            int base = (r - 1)/2;
        	for (int j = 0; j < len; ++j)
        	{
        		res[i][base + r * levelvec[i][j].pos] = to_string(levelvec[i][j].val);
        	}
        }

        return res;
    }