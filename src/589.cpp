vector<int> preorder(Node* root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        search(root, res);
        
        return res;
    }
    
    void search(Node* node, vector<int>& res)
    {
        res.push_back(node->val);
        int len = (node->children).size();
        if (len != 0)
        {
            for (int i = 0; i < len; ++i)
            {
                search((node->children)[i], res);
            }    
        }
    }