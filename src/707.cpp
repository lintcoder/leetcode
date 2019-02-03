class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len)
        return -1;
        Node* node = head;
        int i = 0;
        while (node != nullptr && i != index)
        {
            node = node->next;
            ++i;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* tmp = new Node(val);
        tmp->next = head;
        head = tmp;
        ++len;
        if (len == 1)
        tail = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        ++len;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len)
        return;
        else if (index == len)
        addAtTail(val);
        else if (index == 0)
        addAtHead(val);
        else
        {
            Node* node = new Node(val);
            Node* tmp = head;
            Node* k = head->next;
            int i = 1;
            while (i < index)
            {
                tmp = k;
                k = tmp->next;
                ++i;
            }
            tmp->next = node;
            node->next = k;
            ++len;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= len || index < 0)
        return;
        if (index == 0)
        {
            Node* node = head;
            head = head->next;
            delete node;
            --len;
        }
        else
        {
            Node* tmp = head;
            Node* k = head->next;
            int i = 1;
            while (i < index)
            {
                tmp = k;
                k = tmp->next;
                ++i;
            }
            tmp->next = k->next;
            delete k;
            if (tmp->next == nullptr)
            tail = tmp;
            --len;
        }
    }
private:
    struct Node
    {
        int val;
        Node* next;
        Node(int v):val(v){next = nullptr;}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int len = 0;
};
