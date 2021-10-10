Node* connect(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;
        
        doconnect(root);
        
        return root;
    }
    
    void doconnect(Node* node)
    {
        if (node->left != nullptr)
        {
            Node* tmp = node;
            Node* nd = node->left;
            while (tmp->next != nullptr)
            {
                nd->next = tmp->right;
                nd = tmp->next->left;
                tmp->right->next = nd;
                tmp = tmp->next;
            }
            nd->next = tmp->right;
            doconnect(node->left);
        }
    }