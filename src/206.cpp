ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* p = head;
    ListNode* q = head->next;
    p->next = NULL;
    while (q->next != NULL)
    {
        ListNode* k = q->next;
        q->next = p;
        p = q;
        q = k;
    }
    q->next = p;

    return q;
}
