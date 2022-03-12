vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* pre = head, *cur = head->next, *post = head->next->next;
        int lastindex = -1, nextindex = -1, firstindex = -1;
        int n = 1;
        int mindist = 1e5;
        while (post != nullptr)
        {
            if ((cur->val < pre->val && cur->val < post->val)
                || (cur->val > pre->val && cur->val > post->val))
            {
                lastindex = nextindex;
                nextindex = n;
                if (lastindex == -1)
                {
                    firstindex = n;
                }
                else
                {
                    int dist = nextindex - lastindex;
                    if (dist < mindist)
                        mindist = dist;
                }
            }
            pre = cur;
            cur = post;
            post = post->next;
            ++n;
        }
        
        vector<int> res(2, -1);
        if (lastindex != -1 && nextindex != -1)
        {
            res[0] = mindist;
            res[1] = nextindex - firstindex;
        }
        
        return res;
    }