Node* connect(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;
        
        doconnect(root);
        
        return root;
    }
    
    void doconnect(Node* node)
    {
        Node* tmp = node;
        Node* first = nullptr;
        while (tmp != nullptr)
        {
            if (tmp->left != nullptr)
            {
                first = tmp->left;
                break;
            }
            if (tmp->right != nullptr)
            {
                first = tmp->right;
                break;
            }
            tmp = tmp->next;
        }
        
        if (first != nullptr)
        {
            Node* nd = first;
            if (tmp->left == first && tmp->right != nullptr)
            {
                nd->next = tmp->right;
                nd = tmp->right;
            }
            
            Node* cur = tmp->next;
            while (cur != nullptr)
            {
                if (cur->left != nullptr)
                {
                    nd->next = cur->left;
                    nd = cur->left;
                }
                if (cur->right != nullptr)
                {
                    nd->next = cur->right;
                    nd = cur->right;
                }
                cur = cur->next;
            }
            
            doconnect(first);
        }
    }