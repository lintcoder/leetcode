int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        int maxdepth = 0;
        maxdepth = search(root);
        
        return maxdepth+1;
    }
    
    int search(Node* node)
    {
        auto& vec = node->children;
        int len = vec.size();
        if (len == 0)
            return 0;
        
        int maxd = 0;
        for (int i = 0; i < len; ++i)
        {
            int t = search(vec[i]);
            if (t > maxd)
                maxd = t;
        }
        
        return maxd+1;
    }
