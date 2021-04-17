vector<string> removeSubfolders(vector<string>& folder) {
        int len = folder.size();
        sort(folder.begin(), folder.end());
        list<string> lst(folder.begin(), folder.end());
        
        auto iter = lst.begin();
        auto iter_next = ++iter;
        --iter;
        while (true)
        {
            auto iter_end = lst.end();
            if (iter == iter_end || iter_next == iter_end)
                break;
            if ((*iter_next).find(*iter) == 0 && (*iter_next)[(*iter).size()] == '/')
                iter_next = lst.erase(iter_next);
            else
            {
                ++iter;
                ++iter_next;
            }
        }
        
        return vector<string>(lst.begin(), lst.end());
    }