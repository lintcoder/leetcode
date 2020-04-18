class FindElements {
public:
    FindElements(TreeNode* root) {
        head = root;
        if (root != nullptr)
        {
            root->val = 0;
            deque<TreeNode*> dq;
            dq.push_back(root);
            elem.push_back(0);
            int len = 1;
            
            while(len != 0)
            {
                for (int i = 0; i < len; ++i)
                {
                    TreeNode* node = dq[i];
                    if (node->left != nullptr)
                    {
                        node->left->val = 2*node->val + 1;
                        elem.push_back(node->left->val);
                        dq.push_back(node->left);
                    }
                    if (node->right != nullptr)
                    {
                        node->right->val = 2*node->val + 2;
                        elem.push_back(node->right->val);
                        dq.push_back(node->right);
                    }
                }
                
                dq.erase(dq.begin(), dq.begin()+len);
                len = dq.size();
            }
            
            sort(elem.begin(), elem.end());
        }
    }
    
    bool find(int target) {
        return binary_search(elem.begin(), elem.end(), target);
    }
private:
    TreeNode* head;
    vector<int> elem;
};