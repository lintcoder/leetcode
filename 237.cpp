void deleteNode(ListNode* node) {
    ListNode* p = node;
    ListNode* q = node->next;
    while (q->next != NULL)
    {
        p->val = q->val;
        p = q;
        q = q->next;
    }
    p->val = q->val;
    delete q;
    p->next = NULL;
}
