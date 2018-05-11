RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
          return nullptr;
        RandomListNode* h = head;
        map<RandomListNode*, int> mp;
        map<int, RandomListNode*> mp_cp;

        int i = 0, j = 0;
        RandomListNode* head_cp = new RandomListNode(h->label);
        RandomListNode* node = head_cp;
        mp[h] = i++;
        mp_cp[j++] = head_cp;
        h = h->next;

        while (h != nullptr)
        {
          node->next = new RandomListNode(h->label);
          node = node->next;
          mp[h] = i++;
          mp_cp[j++] = node;
          h = h->next;
        }
        for (auto m : mp)
        {
          if (m.first->random != nullptr)
              mp_cp[m.second]->random = mp_cp[mp[m.first->random]];
        }
        return head_cp;
    }