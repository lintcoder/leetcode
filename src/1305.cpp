vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        midtravel(root1, res);
        midtravel(root2, res);
        
        sort(res.begin(), res.end());
        
        return move(res);
    }
    
    void midtravel(TreeNode* node, vector<int>& vec)
    {
        if (node != nullptr)
        {
            midtravel(node->left, vec);
            vec.push_back(node->val);
            midtravel(node->right, vec);
        }
    }