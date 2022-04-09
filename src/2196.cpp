TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, int> nodeflag;
        map<int, pair<int,int>> nodepos;
        int len = descriptions.size();
        
        for (int i = 0; i < len; ++i)
        {
            nodeflag[descriptions[i][0]] |= 1;
            nodeflag[descriptions[i][1]] |= 2;
            if (descriptions[i][2] == 1)
                nodepos[descriptions[i][0]].first = descriptions[i][1];
            else
                nodepos[descriptions[i][0]].second = descriptions[i][1];
        }
        
        int headval = 0;
        auto iterLast = nodeflag.end();
        for (auto iter = nodeflag.begin(); iter != iterLast; ++iter)
        {
            if (iter->second == 1)
            {
                headval = iter->first;
                break;
            }
        }
        
        TreeNode* head = new TreeNode(headval);
        deque<TreeNode*> dq;
        dq.push_back(head);
        int k = 1;
        while (k != 0)
        {
            int n = 0;
            for (int i = 0; i < k; ++i)
            {
                TreeNode* node = dq[i];
                if (nodepos[node->val].first != 0)
                {
                    node->left = new TreeNode(nodepos[node->val].first);
                    dq.push_back(node->left);
                    ++n;
                }
                if (nodepos[node->val].second != 0)
                {
                    node->right = new TreeNode(nodepos[node->val].second);
                    dq.push_back(node->right);
                    ++n;
                }
            }
            dq.erase(dq.begin(), dq.begin()+k);
            k = n;
        }
        
        return head;  
    }